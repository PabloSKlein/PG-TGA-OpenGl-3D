#include "Group.h"



Group::Group()
{
}


Group::~Group()
{
}

void Group::AddFace(std::vector<int> vertexIndices, std::vector<int> normalIndices, std::vector<int> mappingIndices)
{
	if (vertexIndices.size() > 3) {
		//faces must be divided on 1, 2, 3 e 1, 3, 4
		std::vector<int> verFace1;
		std::vector<int> norFace1;
		std::vector<int> mapFace1;
		std::vector<int> verFace2;
		std::vector<int> norFace2;
		std::vector<int> mapFace2;

		//first element belongs to the first and second face
		verFace1.push_back(vertexIndices.front());
		verFace2.push_back(vertexIndices.front());
		vertexIndices.erase(vertexIndices.begin());
		if (normalIndices.size() > 0 && mappingIndices.size() > 0) {
			norFace1.push_back(normalIndices.front());
			norFace2.push_back(normalIndices.front());
			normalIndices.erase(normalIndices.begin());
			mapFace1.push_back(mappingIndices.front());
			mapFace2.push_back(mappingIndices.front());
			mappingIndices.erase(mappingIndices.begin());
		}
		//second element belongs to first face only
		verFace1.push_back(vertexIndices.front());
		vertexIndices.erase(vertexIndices.begin());
		if (normalIndices.size() > 0 && mappingIndices.size() > 0) {
			norFace1.push_back(normalIndices.front());
			normalIndices.erase(normalIndices.begin());
			mapFace1.push_back(mappingIndices.front());
			mappingIndices.erase(mappingIndices.begin());
		}
		//third element belongs to both faces
		verFace1.push_back(vertexIndices.front());
		verFace2.push_back(vertexIndices.front());
		vertexIndices.erase(vertexIndices.begin());
		if (normalIndices.size() > 0 && mappingIndices.size() > 0) {
			norFace1.push_back(normalIndices.front());
			norFace2.push_back(normalIndices.front());
			normalIndices.erase(normalIndices.begin());
			mapFace1.push_back(mappingIndices.front());
			mapFace2.push_back(mappingIndices.front());
			mappingIndices.erase(mappingIndices.begin());
		}
		//fourth element only belongs to the second face
		verFace2.push_back(vertexIndices.front());
		vertexIndices.erase(vertexIndices.begin());
		if (normalIndices.size() > 0 && mappingIndices.size() > 0) {
			norFace2.push_back(normalIndices.front());
			normalIndices.erase(normalIndices.begin());
			mapFace2.push_back(mappingIndices.front());
			mappingIndices.erase(mappingIndices.begin());
		}
		//add the two faces to the group	
		Face newFace1 = Face(verFace1, norFace1, mapFace1);
		faces.push_back(newFace1);
		Face newFace2 = Face(verFace2, norFace2, mapFace2);
		faces.push_back(newFace2);
	}
	else if (vertexIndices.size() == 3) {
		Face newFace = Face(vertexIndices, normalIndices, mappingIndices);
		faces.push_back(newFace);
	}
}
