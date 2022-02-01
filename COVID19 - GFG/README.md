# COVID19
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given the <strong>N*M</strong> binary matrix, <strong>1</strong> represents the healthy person, and <strong>0</strong> represents a patient affected by a coronavirus. The task is to check the minimum time required for </span><span style="font-size:18px">all persons to get affected. A patient at <strong>[i, j]</strong> cell affects a person at cell <strong>[i, j-1], [i, j+1] [i+1, j]</strong> and <strong>[i-1, j]</strong> in one second. </span></p>

<p><span style="font-size:18px"><strong>Note:</strong> There will be at least one patient </span></p>

<p><span style="font-size:18px"><strong>Input: </strong><br>
1. The first line of the input contains a single integer<em> </em> <strong>T</strong> denoting the number of test cases. The description of&nbsp;<strong>T</strong> test cases follows.<br>
2. The first line of each test case contains two space-separated integers<strong> N </strong>and<strong> M</strong><strong>.</strong><br>
3. Next <strong>N</strong> lines contain <strong>M</strong> space-separated binary integers.<strong> </strong></span></p>

<p><br>
<span style="font-size:18px"><strong>Output:</strong> For each test case, print the minimum time required to all persons affected by COVID19</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1. 1 &lt;= T &lt;= 100</span><br>
<span style="font-size:18px">2. </span><span style="font-size:18px">1 &lt;= N, M &lt;= 100</span><br>
<span style="font-size:18px">3. 0 &lt;= mat[i][j] &lt;= 1</span><br>
<br>
<br>
<span style="font-size:18px"><strong>Example:<br>
Input:</strong></span><br>
<span style="font-size:18px">2</span><br>
<span style="font-size:18px">2 2<br>
1 0<br>
1 0<br>
3 3</span><br>
<span style="font-size:18px">1 1 1<br>
1 0 1<br>
1 1 1</span></p>

<p><strong><span style="font-size:18px">Output:</span></strong><br>
<span style="font-size:18px">1<br>
2</span><br>
<br>
<span style="font-size:18px"><strong>Explanation:<br>
Test Case 2:</strong> After first second matrix will look like {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}. After two seconds matrix will look like {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}.</span></p>
 <p></p>
            </div>