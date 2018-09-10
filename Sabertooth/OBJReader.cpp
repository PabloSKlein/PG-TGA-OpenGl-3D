#include "OBJReader.h"
#include "Mesh.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

OBJReader::OBJReader()
{
	typesMap = {
		{ "v", ObjTypes::V },
		{ "vn", ObjTypes::VN },
		{ "vt", ObjTypes::VT },
		{ "f", ObjTypes::F },
		{ "g", ObjTypes::G },
		{ "mtllib", ObjTypes::MTLLIB },
		{ "usemtl", ObjTypes::USEMTL },
		{ "#", ObjTypes::COMMENTARY },
	};
}


OBJReader::~OBJReader()
{
}

static Mesh *read(string filename) {
	Mesh *mesh = new Mesh;
	
	ifstream arq(filename);

	while (!arq.eof()) {

		string line;
		getline(arq, line);
		stringstream sline;
		sline << line; string temp; sline >> temp;

		if (temp == "v") {
			float x, y, z;
			sline >> x >> y >> z;

			mesh->AddVertex(glm::vec3(x, y, z));

		}
		else if (temp == "vn") {
			float x, y, z;
			sline >> x >> y >> z;

			mesh->AddNormal(glm::vec3(x, y, z));

		}else if (temp == "vt") {
			float x, y;
			sline >> x >> y;

			mesh->AddMapping(glm::vec2(x, y));

		}else if (temp == "f") {
			// implementar lógica de varições 
			// para face: v, v/t/n, v/t e v//n 
			std::vector<int> *posV = new std::vector<int>;
			std::vector<int> *normV = new std::vector<int>;
			std::vector<int> *texV = new std::vector<int>;
			std::string token, valueAux, bloco;
			std::stringstream tokenStream;

			sline >> token;
			
			
			// v1 v2 v3
			if (!token.find('/')) {
				while (tokenStream.rdbuf()->in_avail()) {
					std::getline(tokenStream, valueAux, '/');
					posV->push_back(valueAux[0]);
				
				}
			}
			else {
				while (tokenStream.rdbuf()->in_avail()) {

					std::getline(tokenStream, valueAux, '/');

					posV->push_back(valueAux[0]);

					std::getline(tokenStream, valueAux, '/');

					// v//n
					if (valueAux == "") {
						std::getline(tokenStream, valueAux, '/');
						normV->push_back(valueAux[0]);
					}
					else {
						// v/t
						texV->push_back(valueAux[0]);

						std::getline(tokenStream, valueAux, '/');

						// v/t/n
						if (valueAux != "") {
							normV->push_back(valueAux[0]);
						}
					}

				}
			}


		}else {
			// else-if 
		    // Verificar outras possibilidades: // g 
		} 
			return mesh;
	}
}
