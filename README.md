<img src="http://latex.codecogs.com/gif.latex?1+sin(x)" border="0"/>

- **Binary Tree Postorder Traversal (145)**
	- 要求不用递归实现后序遍历
	- 后序是left-right-root，那么首先用修正的前序root-right-left，然后reverse一下，变成left-right-root就行了，代码如下：

- **Factorial Trailing Zeroes(172)**
	- 给出整数n，求$n!$末尾的0的个数，要求在logarithmic时间内求解
	- 首先容易知道要出现0，只有$2 \times 5 =10$才行，而对于从$1,2,...,n$的这一系列的数，是2的倍数的数明显比5多，因此每一个5一定能找到一个2与之配对，换句话说，0的个数和5的个数一样多，下面只需要找出5的个数就行了，容易知道反复除以5就行，代码如下：

- **Container with most water(11)**
	- 给出一些列的隔板的高度，求问用哪两个隔板装水能装最多的水
	- 求解非常巧妙，左右分别向中间靠拢，指针记为left和right, 如果left的值比right的小，则left往中间移动一格，否则right往中间移动一格

- **Maximal Rectangle(85)**
	- 题目的要求是给出一个0-1矩阵，要求给出一个最大的矩形，使得矩形里面的所有值为1
	- 解法非常巧妙，从上往下扫描，维护三个数组**height**, **left**, **right**，分别存储每一列的信息，当迭代到第i行的时候，left表示从左往右最靠右的0的位置，初始为0；right表示从右往左最靠左的0的位置，初始为cLen+1，因此列的编码是(0, 1, 2, ..., cLen, cLen+1)，然后height存的就是当前单元从上往下连续的1的个数
	- 维护好了这些信息，那么每个单元格的面积就是
$$Area(j) = height(j)*(right(j) - left(j) - 1)$$
	- 值得注意的是，在更新left和right的时候，得查看上一迭代的时候height的值，如果是0，那么本层不受约束，如果是1，那么考虑到上下直接的连通，left的值不能小于旧的left值，right的值不能大于旧的right值
	- 因此最后实现过程中的更新顺序是，对于每一层，先从左往右扫描一次更新left，然后从右往左扫描一次更新right，最后再从左往右扫描一次，更新height和area
