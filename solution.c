void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if (n == 0 && m == 0) {
        return;
    }

    if (n == 0) {
        return;
    }

    if (m == 0) {
        for (int i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
        return;
    }

    // case: nums1 [1, 2, 3, 0, 0, 0] nums2 [4, 5, 6]
    if (nums2[0] > nums1[m - 1]) {
        // insert nums2 at the end of nums1
        for (int i = m, j = 0; i < nums1Size && j < n; i++, j++) {
            nums1[i] = nums2[j];
        }
        return;
    }

    // case: nums1 [4, 5, 6, 0, 0, 0] nums2 [1, 2, 3]
    if (nums2[n - 1] < nums1[0]) {
        // move all positive nums1 elements at the end of the array
        // nums1[m + n - 1] = nums1[m - 1]
        // nums1[m + n - 2] = nums1[m - 2]
        // ...
        // nums1[m + n - m] = nums1[m - m]
        for (int i = nums1Size, j = 1; i >= n && j <=m; j++) {
            nums1[i - j] = nums1[m - j];
        }
        // insert nums2 at the beggining of nums1
        for (int i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
        return;
    }

    // case: nums1 [4,7,9,0,0,0,0] nums2 [3,5,8,11]
    // 3 < 4 => nums1 [3,4,7,9,0,0,0] (j++)
    // 5 > 4 => nums1 [3,4,7,9,0,0,0] (i++)
    // 5 < 7 => nums1 [3,4,5,7,9,0,0] (j++)
    // 8 > 7 => nums1 [3,4,5,7,9,0,0] (i++)
    // 8 < 9 => nums1 [3,4,5,7,8,9,0] (j++)
    // 11 > 9 => nums1 [3,4,5,7,8,9,0] (i++)
    // end of nums1 => add nums2 at the end of nums1 => [3,4,5,7,8,9,11]
    int j = 0, i = 0;
    while (j < n && i < m) {
        if (nums2[j] <= nums1[i]) {
            // shift nums1 one position to the right
            for (int k = m; k > i; k--) {
                nums1[k] = nums1[k-1];
            }

            nums1[i] = nums2[j];

            j++;
            i++;
            m++; 
        } else {
            i++;
        }
    }

    // insert any remaining nums2 elements at the end of nums1
    for (int i = m; i < nums1Size && j < n; i++, j++) {
        nums1[i] = nums2[j];
    }
}
