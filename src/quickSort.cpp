#include <iostream>
#include <iterator>
#include <vector>

using std::vector, std::cout, std::endl;

template <typename randomAccessIterator>
void quickSort(const randomAccessIterator &begin,
               const randomAccessIterator &end) {

  if (begin == end || end - begin <= 1) {
    return; // Base case: if the range is empty or has one element, it's already
            // sorted
  }
  randomAccessIterator left = begin;
  randomAccessIterator right = end - 1;
  randomAccessIterator pivot = begin + (end - begin) / 2;

  while (left <= right) {
    while (*left < *pivot) {
      ++left;
    }
    while (*right > *pivot) {
      --right;
    }
    if (left <= right) {
      std::swap(*left, *right);
      ++left;
      --right;
    }
  }

  quickSort(begin, right + 1);
  quickSort(left, end);
}
int main(int argc, char *argv[]) {
  vector<float> vec2{3.1, 1, 4.3, 1, 5.5542, 9.0, .2, 6};
  vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6};
  quickSort(vec.begin(), vec.end());
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<float>(cout, " "));
  return 0;
}
