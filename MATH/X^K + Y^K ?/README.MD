# SOLVE THE SOLUTION

**Example:**
- x + y = 1
- x<sup>2</sup> + y<sup>2</sup> = 2
- x<sup>11</sup> + y<sup>11</sup> = ?

**Solution:**
- x<sup>2</sup> + y<sup>2</sup> = 2 <=> (x + y)<sup>2</sup> - 2xy = 2
                                     => xy = $\frac{2 - (x + y)^2}{-2}$	= $\frac{-1}{2}$
- x<sup>3</sup> + y<sup>3</sup> = (x + y)(x<sup>2</sup> + y<sup>2</sup>) - (xy)(x + y) = $\frac{5}{2}$
- x<sup>4</sup> + y<sup>4</sup> = (x<sup>2</sup>)<sup>2</sup> + (y<sup>2</sup>)<sup>2</sup> = (x<sup>2</sup> + y<sup>2</sup>)<sup>2</sup> - 2(xy)<sup>2</sup> = $\frac{7}{2}$
- x<sup>5</sup> + y<sup>5</sup> = (x<sup>3</sup> + y<sup>3</sup>)(x<sup>2</sup> + y<sup>2</sup>) - (xy)<sup>2</sup>(x + y) = $\frac{19}{4}$
- x<sup>6</sup> + y<sup>6</sup> = (x<sup>3</sup>)<sup>2</sup> + (y<sup>3</sup>)<sup>2</sup> = (x<sup>3</sup> + y<sup>3</sup>)<sup>2</sup> - 2(xy)<sup>3</sup> = $\frac{13}{2}$
=> we get the general formula:

**General formula x<sup>n</sup> + y<sup>n</sup>:**
+ With n % 2 = 0:
  + K := $\frac{n + 1}{2}$
  + E := n - K
  + x<sup>n</sup> + y<sup>n</sup> = (x<sup>K</sup> + y<sup>K</sup>)(x<sup>E</sup> + y<sup>E</sup>) - (xy)<sup>E</sup>(x + y)

+ With n % 2 ≠ 0
  + K := $\frac{n}{2}$
  + x<sup>n</sup> + y<sup>n</sup> = (x<sup>K</sup> + y<sup>K</sup>)<sup>2</sup> - 2(xy)<sup>K</sup>

Applying it to the previous example, we have: n = 11 => n % 2 ≠ 0
  + K := $\frac{11 + 1}{2}$ = 6
  + E := n - K = 11 - 6 = 5
  + x<sup>11</sup> + y<sup>11</sup> = (x<sup>6</sup> + y<sup>6</sup>)(x<sup>5</sup> + y<sup>5</sup>) - (xy)<sup>5</sup>(x + y) = $\frac{989}{32}$
