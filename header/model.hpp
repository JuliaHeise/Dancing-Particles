#ifndef MODEL
#define MODEL

template<int N>
class Model{
    public:
        Model();
        Model<N>(float ver[], int idx[]);
        Model<N>(Model<N> m);
        ~Model();

        float[] getVert(){ return vertices; };
        int[] getIdx(){ return indices; };

    private:
        float vertices[];
        int indices[];
};

#endif