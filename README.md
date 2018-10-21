# ArbitraryPHP - 任意PHP代码执行扩展

这是一个实验性的PHP扩展，加载这个扩展后，每次请求将可以执行一段自己的PHP代码。

## 安装

选择对应版本的PHP，下载[Releases](https://github.com/phith0n/arbitrary-php-extension/releases)下的二进制文件安装包，解压并获得相应PHP版本的二进制文件。

执行`php -i |grep extension_dir`，获取扩展目录：

![](screenshot/1.png)

将二进制文件arbitraryphp.so移动到扩展目录中，并修改php.ini，开启这个扩展：

```
extension=arbitraryphp.so
```

## 使用

请求任意一个PHP，在参数`arbitrary_php`中增加任意PHP代码，即可执行：

![](screenshot/2.png)

也可以是POST请求:

![](screenshot/3.png)