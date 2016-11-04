//reader.h
#ifndef READER_H
#define READER_H

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>

const int MAX_VERT=300000;

struct Vertex {

    float x;
    float y;
    float z;

};


class Reader {
    private:
        Vertex vertex[256];

    public:
        Reader();
        ~Reader();


        std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
        std::vector< glm::vec3 > temp_vertices;
        std::vector< glm::vec2 > temp_uvs;
        std::vector< glm::vec3 > temp_normals;
        std::vector < glm::vec3 > out_vertices;

        void load(char* filename);
        void draw(char* filename);


};

#endif
