#include "OBJReader.h"
#include "Mesh.h"
#include <fstream>
#include <sstream>


OBJReader::OBJReader()
{
}


OBJReader::~OBJReader()
{
}

Mesh *read(string filename) {
	Mesh *mesh = new Mesh;
	ifstream arq(filename);

	while (!arq.eof()) {
		string line;
		getline(arq, line);
		stringstream sline;
		sline << line; string temp; sline >> temp;
		if (temp == "v") {
			// ler vértice ... 
			float x, y, z;
			sline >> x >> y >> z;
			// ... atribuir vértices da malha // 
		}
		else if (temp == "f") {
			// implementar lógica de varições 
			// para face: v, v/t/n, v/t e v//n 
			string token;
			sline >> token;
			// v/t/n, por exemplo 
			stringstream stoken;
			string aux;
			getline(stoken, aux, '/'); //
		}
		else {
			// else-if 
		    // Verificar outras possibilidades: // g, vn, } 
			return mesh;
		}
	}
}
