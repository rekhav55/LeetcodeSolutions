# Counting elements in two arrays
##  Easy 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given two unsorted arrays <strong>arr1[]</strong> and <strong>arr2[]</strong>. They may contain duplicates. For each element in arr1[] count elements less than or equal to it in array arr2[].</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>m = 6, n = 6
arr1[] = {1,2,3,4,7,9}
arr2[] = {0,1,2,1,1,4}
<strong>Output: </strong>4 5 5 6 6 6<strong>
Explanation: </strong>Number of&nbsp;elements less than
or equal to 1, 2, 3, 4, 7, and 9 in the
second array are respectively 4,5,5,6,6,6</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>m = 5, n = 7
arr1[] = {4 8 7 5 1}
arr2[] = {4,48,3,0,1,1,5}
<strong>Output: </strong>5 6 6 6 3</span></pre>

<p><span style="font-size:18px"><strong>Your Task :</strong><br>
Complete the function&nbsp;<strong>countEleLessThanOrEqual()&nbsp;</strong>that takes two array arr1[], arr2[],&nbsp;&nbsp;m, and n&nbsp;as input and returns an array containing the required results(the count of elements less than or equal to it in arr2 for each element in arr1 where i<sub>th</sub> output represents the count for i<sub>th</sub> element in arr1.)</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O((m + n) * log n).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=m,n&lt;=10^5<br>
1&lt;=arr1[i],arr2[j]&lt;=10^5</span></p>
 <p></p>
            </div>