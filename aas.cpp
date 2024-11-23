#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> merge_arrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    int m1=0,m2=0;
    std::vector<int> result_array;

        while(true) {

            if (m1>=nums1.size())
            {   
                for(int i=m2;i<=nums2.size()-1;i++){
                    result_array.push_back(nums2[i]);
                }
                break;
            }
            if(m2>=nums2.size()) { 

                for(int i=m1;i<=nums1.size()-1;i++){
                    result_array.push_back(nums1[i]);
                }
                break;
            }
        
            // process
            if(nums1[m1]<nums2[m2]){
                result_array.push_back(nums1[m1]);
                m1++;
            }
            else if(nums2[m1]<nums1[m2]){
                result_array.push_back(nums2[m2]);
                m2++;
            }
            else{
                result_array.push_back(nums1[m1]);
                result_array.push_back(nums2[m2]);
                m1++;m2++;
               }
        }

    return result_array;
}

void test_exhaust_array1() {
    const auto nums1 = std::vector<int>{1,2,3,4,5};
    const auto nums2 = std::vector<int>{2,3,4,10};
    const auto result = merge_arrays(nums1, nums2);
    std::vector<int> expected{1,2,2,3,3,4,4,5,10};
    assert(result==expected && "test failed array");
    std::cout<<"Test passed\n";
}

void test_exhaust_array2() {
    const auto nums1 = std::vector<int>{11,21,32,41,51,61};
    const auto nums2 = std::vector<int>{10,12,30,33};
    const auto result = merge_arrays(nums1, nums2);
    std::vector<int> expected{10,11,12,21,30,32,33,41,51,61};
    assert(result==expected && "test failed array2 ");
    std::cout<<"Test passed \n";
}

void test_empty_array() {
    const auto nums1 = std::vector<int>{};
    const auto nums2 = std::vector<int>{2,3,4,10};
    const auto result = merge_arrays(nums1, nums2);
    std::vector<int> expected{2,3,4,10};
    assert(result==expected && "test failed array");
    std::cout<<"Test passed \n";
}
void test_exhaust_array3(){
    const auto nums1=std::vector<int>{1,1,1,1};
    const auto nums2=std::vector<int>{0,0,0,0};
    const auto result=merge_arrays(nums1,nums2);
    std::vector<int> expected{0,0,0,0,1,1,1,1};
    assert(result==expected && "test failed at array3");
    std::cout<<"Test passed \n";
}


int main(){
    //Test cases1: nums1={11,21,32,41,51,61}
    //               nums2={10,12,30,33}

    //Test cases2: nums1={}
    //             nums2={0}
    //Test cases3: nums1={}
    //              nums2={1,3,4,5}
    //Test cases4: nums1={0,0,0,0}
    //              nums2={1,1,1,1}
   
    test_exhaust_array1();
    test_exhaust_array2();
    test_exhaust_array3();
    test_empty_array();
}