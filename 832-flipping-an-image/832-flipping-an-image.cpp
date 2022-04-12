class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int j=0;j<image.size();j++){
            reverse(image[j].begin(),image[j].end());
            for(int i=0;i<image[j].size();i++){
                image[j][i]=(image[j][i]^1);
                cout<<image[j][i]<<" ";
            }
            cout<<endl;
        }
        return image;
    }
};