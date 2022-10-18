class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        '''
        len1 = nums1->length , len2 = nums2->length
        variables : repeat , ptr1 , ptr2 , ans[]
        
        loop ptr1 < len1 and ptr2 < len2
           if nums[ptr1] == nums[ptr2] and repeat != nums[ptr1]:
                     repeat = nums[ptr1]
                     ans.append(nums[ptr1])
                     ptr1+=1
                     ptr2+=1
           elif nums[ptr1] < nums[ptr2]:
                  ptr1++
                  we have to move forward then only we can get upto that since arrays are sorted
           else :
                  ptr2++
        
        
        Now , why we need to take repeat cause " Each element in the result must be unique " 
        as mentioned in question
        
        we cannot take the values which we already have
        
        '''
        nums1.sort()
        nums2.sort()
        len1 = len(nums1)
        len2 = len(nums2)
        repeat = -1 
        ptr1 , ptr2 = 0 , 0 
        ans = []
        
        while ptr1 < len1 and ptr2 < len2:
            if nums1[ptr1] == nums2[ptr2] and repeat != nums1[ptr1]:
                repeat = nums1[ptr1]
                ans.append(nums1[ptr1])
                ptr1+=1
                ptr2+=1
            elif nums1[ptr1] < nums2[ptr2]:
                ptr1+=1
            else:
                ptr2+=1
        return ans