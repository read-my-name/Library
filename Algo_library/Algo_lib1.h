#pragma once
#include "include.h"
class Algo_lib1
{
	//friend main;
	public:
		Algo_lib1();
		~Algo_lib1();

	private:
		struct TreeNode
		{
			int val;
			TreeNode* left;
			TreeNode* right;
			TreeNode() : val(0), left(nullptr), right(nullptr) {}
			TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
			TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
		};

	private:
		int nAdd(int nA, int nB);
		int nSubtract(int nA, int nB);
		int lengthOfLongestSubstring(std::string szMsg); //All lower case
		bool checkInclusion(std::string sz1, std::string sz2);
		std::vector<std::vector<int>> vecFloodFill(std::vector<std::vector<int>>& vecImage, int nRow, int nCol, int nNewColor);
		//Depth First Search
		void vDFS(std::vector<std::vector<int>>& image, int i, int j, int val, int newColor);
		int nMaxAreaOfIsland(std::vector<std::vector<int>>& grid);
		void vDfs(int i, int j, std::vector<std::vector<int>>& grid, int& count);
		TreeNode* stMergeTrees(TreeNode* root1, TreeNode* root2);
};

