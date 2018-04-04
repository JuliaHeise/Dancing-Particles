#ifndef MODEL
#define MODEL
template<int P, int T> //num Points, num Triangles
class Model{
    public:
        Model();
        Model(const float* ver,const int* idx);
        Model(const Model &m);
        ~Model();


        float* getVert(){ return &vertices; };
        unsigned int* getIdx(){ 
            unsigned int* d = &indices;
            return d; };

    private:
        float vertices[3*P];
        unsigned int indices[3*T];
        const int numPoints;
        const int numTriangles;
};

#endif