#include <iostream>
#include <queue>

using namespace std;

class KthLargest {
  private:
    int k;
    priority_queue <int, vector<int>, greater<int>> min_heap;
  public:
    KthLargest(int k, vector<int>& nums) {
      this->k = k;

      for (int num : nums) {
        this->min_heap.push(num);
      }

      while (this->min_heap.size() > this->k) {
        this->min_heap.pop();
      }
    }

    int add(int val) {
      this->min_heap.push(val);

      if (this->min_heap.size() > this->k) {
        this->min_heap.pop();
      }

      return this->min_heap.top();
    }
};

int main(void) {
  vector<int> input = {4, 5, 8, 2};
  int k = 3;

  KthLargest kl = KthLargest(k, input);

  int result_test1 = kl.add(3);
  cout << "Add 3: Kth largest num is " << result_test1 << endl;

  int result_test2 = kl.add(5);
  cout << "Add 5: Kth largest num is " << result_test2 << endl;

  int result_test3 = kl.add(10);
  cout << "Add 10: Kth largest num is " << result_test3 << endl;

  int result_test4 = kl.add(9);
  cout << "Add 9: Kth largest num is " << result_test4 << endl;

  int result_test5 = kl.add(4);
  cout << "Add 4: Kth largest num is " << result_test5 << endl;
    
  return 0;
}