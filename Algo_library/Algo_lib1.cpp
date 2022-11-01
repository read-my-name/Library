#include "Algo_lib1.h"

Algo_lib1::Algo_lib1()
{
	std::cout << "Algo_lib1 Created" << "\n";
}

Algo_lib1::~Algo_lib1()
{
	std::cout << "Algo_lib1 Destroyed" << "\n";
}

int Algo_lib1::nAdd(int nA, int nB)
{
	//std::cout << nA + nB << "\n";
	return nA + nB;
}

int Algo_lib1::nSubtract(int nA, int nB)
{
    return nA - nB;
}

int Algo_lib1::lengthOfLongestSubstring(std::string szMsg) //All is lower case
{
    int nErase = 0;
    int nInsert = 0;
    int nLongest = 0;
    std::unordered_set<char> us;

    while (nInsert < szMsg.length())
    {
        if (us.find(szMsg[nInsert]) == us.end())
        { //will only enter when there's no same char inside, Eg: null
            us.insert(szMsg[nInsert]);
            nLongest = nLongest > nInsert - nErase + 1 ? nLongest : nInsert - nErase + 1; //max(nLongest, nInsert - nErase + 1)
            ++nInsert;
        }
        else
        { //enter here if found same char
            us.erase(szMsg[nErase]);
            ++nErase;
        }
    }
    return nLongest;
}

bool Algo_lib1::checkInclusion(std::string sz1, std::string sz2)
{//https://leetcode.com/problems/permutation-in-string/solutions/638531/java-c-python3-detailed-explanation-o-n-time/
    int nMap[26] = { 0 };
    int j = 0, i = 0, nCount_chars = sz1.size();

    for (char c : sz1)
    { // convert char into ascii value (a = 97)
        nMap[c - 'a']++;
    }
    while (j < sz2.size())
    {
        if (nMap[sz2.at(j++) - 'a']-- > 0)
        {
            nCount_chars--;
        }
        if (nCount_chars == 0)
        {
            return true;
        }
        if (j - i == sz1.size() && nMap[sz2.at(i++) - 'a']++ >= 0)
        {//short circuiting if the 1st condition is false with 'AND', and true with 'OR'
            nCount_chars++;
        }
    }
    return false;
}

void Algo_lib1::vDFS(std::vector<std::vector<int>>& image, int i, int j, int val, int newColor)
{//https://leetcode.com/problems/flood-fill/solutions/2750194/easy-explanation-in-c/
    if (i < 0 || i >= image.size() 
            || j < 0 || j >= image[0].size() 
            || image[i][j] == newColor 
            || image[i][j] != val)
    {
        return;
    }
    image[i][j] = newColor;
    vDFS(image, i - 1, j, val, newColor);
    vDFS(image, i + 1, j, val, newColor);
    vDFS(image, i, j - 1, val, newColor);
    vDFS(image, i, j + 1, val, newColor);
}

std::vector<std::vector<int>> Algo_lib1::vecFloodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor)
{
    int val = image[sr][sc];
    vDFS(image, sr, sc, val, newColor);
    return image;
}

void Algo_lib1::vDfs(int i, int j, std::vector<std::vector<int>>& grid, int& count)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
    {
        return;
    }
    count++;
    grid[i][j] = 0;
    vDfs(i - 1, j, grid, count);
    vDfs(i, j + 1, grid, count);
    vDfs(i, j - 1, grid, count);
    vDfs(i + 1, j, grid, count);
}
int Algo_lib1::nMaxAreaOfIsland(std::vector<std::vector<int>>& grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            { //only start search when it is "1"
                int c = 0;
                vDfs(i, j, grid, c);
                count = std::max(count, c);
            }
        }
    }
    return count;
}

Algo_lib1::TreeNode* Algo_lib1::stMergeTrees(TreeNode* root1, TreeNode* root2)
{
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;
    TreeNode* temp = new TreeNode(root1->val + root2->val);

    if (root1->left != NULL || root2->left != NULL)
    {
        temp->left = stMergeTrees(root1->left, root2->left);
    }
    if (root1->right != NULL || root2->right != NULL)
    {
        temp->right = stMergeTrees(root1->right, root2->right);
    }
    return temp;
}