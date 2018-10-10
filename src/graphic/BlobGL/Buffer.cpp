#include <BlobEngine/BlobGL/Buffer.hpp>

#include <BlobEngine/Reader/FileReader.hpp>
#include <iostream>

using namespace BlobEngine::Reader;
using namespace std;

void BlobEngine::BlobGL::Buffer::load(int num, JsonExplorer explorer) {
	explorer.goToBaseNode();

	explorer.goToArrayElement("buffers", num);

	uri = explorer.getString("uri");

	if (explorer.hasMember("byteLength"))
		byteLength = static_cast<size_t>(explorer.getInt("byteLength"));

	FileReader fileReader(FileReader::getFilePath(JsonExplorer::path) + uri);

	if (fileReader.getSize() != byteLength)
		throw BlobException("File typeSize don't fit");

	data.resize(byteLength);

	for (int i = 0; i < byteLength; i++)
		data[i] = fileReader.readNextByte();

	for (unsigned char &i : data)
		cout << hex << uppercase << (unsigned int) i << ' ';

	cout << endl;
}
