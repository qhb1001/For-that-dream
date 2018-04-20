# JAVA大数

#### HDU1063

本题需要使用两个内建的方法

一个是BigDecimal中的stripTrailingZeros()，用于去除小数后的零。如果小数点后全都是零，那么会返回一个不含小数点的大数。

另一个是BigDecimal中的toPlainString()，用于将改类型转换为String类型

由于本题需要把前缀0都取消掉，所以在转换成String之后，操作就灵活了起来

String访问某个索引下的数据时，需要使用charAt()方法