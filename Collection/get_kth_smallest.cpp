// You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.


// For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].


// • Return the kth smallest fraction considered. 
// • Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].


// Example 1:
// • Input: arr = [1,2,3,5], k = 3
// • Output: [2,5]
// • Explanation: The fractions to be considered in sorted order are:
// • 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
// • The third fraction is 2/5.


std::vector<int> kthSmallestFraction(std::vector<int>& arr, int k) {
    std::map<std::pair<int, int>, double> fractions;

    // Calculate all possible fractions and store them in the map
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            double fraction = static_cast<double>(arr[i]) / arr[j];
            fractions[{i, j}] = fraction;
        }
    }

    // Sort the map in ascending order based on the fraction values
    std::vector<std::pair<std::pair<int, int>, double>> sortedFractions(fractions.begin(), fractions.end());
    std::sort(sortedFractions.begin(), sortedFractions.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    // Return the kth smallest fraction as the answer
    return { arr[sortedFractions[k - 1].first.first], arr[sortedFractions[k - 1].first.second] };
}