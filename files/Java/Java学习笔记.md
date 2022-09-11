# Java-notes

## 课内部分

### Chapter-1（Java 概述）

1. Java技术的**通用性**、**高效性**、**平台移植性**和**安全性**，使之成为网络计算的理想技术
2. Java语言是一种高级编程语言，它具有**简单、结构中立、面向对象、可移植、分布式、高性能、多线程、健壮、动态、安全**等特点

### Chapter-2 （Java基础）

1. **标识符**：为程序中的各个元素进行命名，这种命名的记号，就是标识符（Identifier）
2. **标识符规则**：在Java 中标识符是以字母、下划线（_）、美元符号（$）等开始的一个字符序列，不能包含运算符和一些特殊字符，如#、*等
3. **关键字**：Java中所有的关键字都为小写，不允许对关键字赋予其他含义
4. **变量与常量**：
   - 变量的命名： `int i; public int j;` 
   - 常量的命名：`final int k = 1;`
5. **变量的邻近原则**：若在一个作用域中，如果有多个同名的变量可以访问，则按照“邻近”原则，在当前域中定义的变量隐藏其它同名的变量。
6. **数据类型**：

| 数据类型 | 所占位数 | 数的范围                             |
| -------- | -------- | ------------------------------------ |
| byte     | 8        | -2<sup>7</sup> ~ (2<sup>7</sup>-1)   |
| short    | 16       | -2<sup>15</sup> ~ (2<sup>15</sup>-1) |
| int      | 32       | -2<sup>31</sup> ~ (2<sup>31</sup>-1) |
| long     | 64       | -2<sup>63</sup> ~ (2<sup>63</sup>-1) |

7. **运算符**：
   - "%"（求模运算符）的操作数可为浮点数, 如 52.3%10=2.3
   - “+” 运算符可用作连接字符串；如果一个操作数是非字符串，其他操作数会自动转化为字符串，如 String s; s="s:"+6*5
8. for循环：Java允许两个或两个以上的变量控制for循环

### Chapter-3（数组）

1. **数组的创建**：

   - Step1 定义数组 ：数组元素类型 数组名[ ]    如 `int num_array[];` 
   - Step2 生成数组 ：数组名=new 数组元素类型[数组长度]  如 `num_array = new int[5];`
   - Step3 初始化数组 ：使数组中的各个元素有确定的数值   如 `num_array[1] = 15;`

   或直接将内存分配放在一个语句中： `int num_array[] = {0, 1, 2};`

2. Java定义数组时，不会为数组分配存储空间

3. **Arrays类**：Arrays类提供了多个操作数组的静态方法

   - **binarySearch**(type[] a,type key)：使用二分搜索法在数组a中搜索指定值key
   - **equals**(type[] a,type[] b)：比较两个数组是否相等
   - **sort**(type[] a)：对数组a进行排序(默认升序)
   - **fill** (type[] a, type val)：用一个指定的值val填充数组a

   例：`Arrays.sort(num_array);`

### Chapter-4（类和对象设计）

1. 面向对象基础
   - 多态：类中同一名称的行为（方法）可以有多种不同的功能，或者相同的接口有多种实现方法。
   
2. 用户必须先**定义类**，并**生成该类的实例**，然后才能通过该实例访问其成员变量和方法。

3. 格式：

   [类修饰符] class 类名 [extends 父类名] [implements 接口名]  {
                  //类体，包括定义类的成员变量 和 成员方法

    }

4. 包（package）：package语句必须是程序的第一条非空格、非注释语句；同一个包中，类不可以重名，但是不同的包中允许相同的类名出现

   - 格式：package pkg1[．pkg2[．pkg3…]];
   - **import：** pkg1.pkg2.* （*可以导入pkg2中所有的类）
   - **import static:** 用于导入指定类的某个静态成员变量 / 方法 / 或全部静态成员变量 / 方法（例如可以直接导入Math类中的变量PI）

5. 修饰符：

- **Public:** 使用public，意味着public之后的成员声明对每个人都是有用的；修饰类时，一个类中最多只能有一个public，且类名需要与文件名相同

- **Private:** 即便是处于同一个包内的其他类也是不可以访问private成员的，通俗说就是自己隔离了自己

- **Protected:** protected处理的是继承的概念。只有**继承他的类**才可以访问他的方法（与public的区别是，只有**同一个包中的类才可以访问**）

- **Default:** 如果类成员前没有使用public,protected,private中的任何一个修饰符，我们称它使用了缺省(default)修饰符；只有该类本身以及与该类在同一个包中的其它类才可以直接访问这些缺省成员（与protected的区别是，不同包中的子类不可以访问）

- **Final:** 

  - 修饰**类**时：不可被继承；

  - 修饰**方法**时，不可被重写，**可以被继承**；

  - 修饰**引用**时，若为基本数据类型，则为常量，不可修改；若为引用数据类型，则地址不可修改，对象本身的属性可以修改

    final int[] {1, 3, 2}; arr[2] = 4; ~~arr = new int[] {12341};~~（不可修改地址）

- **Static:** 可以在没有创建对象的情况下来进行调用（方法/变量）

  - 修饰**方法**时：静态方法，可以在没有创建对象的情况下来进行调用（方法/变量），不依附于任何对象，因此没有this；静态方法**不可以**访问成员的非静态方法/变量；非静态方法可以访问静态方法/变量

  - 修饰**变量**时：静态变量，静态变量被所有的对象所共享，在内存中只有一个副本，它当且仅当在类初次加载时会被初始化。而非静态变量是对象所拥有的，在创建对象的时候被初始化，存在多个副本，各个对象拥有的副本互不影响

    - 静态变量不属于单个对象，而属于整个类。若其中一个对象对其进行修改，通过类再次访问该对象值时，该值已经被改变

      ```java
      public class Chapter3 {
          static int num = 100;
          static void print() {
              System.out.println(num);
          }
          public static void main(String[] args) {
              Chapter3.print();
              Chapter3 tomcat = new Chapter3();
              tomcat.num = 120;
              tomcat.print();
              Chapter3.print();
          }
      }
      /*
      结果：
      100
      120
      120
      */
      ```
  
  - 修饰**代码块**时：用来形成静态代码块以优化程序性能。static块可以置于类中的任何地方，类中可以有多个static块。在类初次被加载的时候，会按照static块的顺序来执行每个static块，并且只会执行一次
  
    static { 
  
    //代码块（只会在类加载的时候执行一次）
  
    }
  
  - **注意⚠️**：Java中的static不可以用于修饰局部变量；static不改变成员的访问权限（只受public private protected影响）

### Chapter-5 （继承与多态）

1. **继承**：Java只支持单继承，即只能有一个父类，但类之间的继承可以具有传递性；子类可以通过继承获得父类中**除访问权限为private**的成员变量和方法

   - 格式：

     class  子类名  extends  父类名{
          类体
     }

2. **重写（override）**：在类的继承过程中，如果子类中新增的变量和方法与父类中的变量和方法**同名**，则称为重写（或覆盖）；方法重写不仅要求父类与子类中的方法名称相同，而且参数列表也要相同，只是实现的功能不同

3. **super**：

   1. 用来**引用当前对象的父类**，可以使用它访问父类中被覆盖的成员
      - 格式：super.method
      
   2. **调用父类中的某一个构造函数**（应该为构造函数中的第一条语句）；若类没有任何构造方法，编译器会自动添加一个无参构造方法，在此方法中只有一条语句super()，若已有有参的构造方法，则不会自动添加
      - 格式：super(参数);
      
      ```java
      public class Chapter3 {
          int id = 3;
          public Chapter3() {
              System.out.println("CHAPTER3 was created!!!!");
          }
          public int show() {
              System.out.println("I'm Chapter3");
              return id;
          }
      }
      
      class min_chapter extends Chapter3 {
          int id = 1;
          min_chapter() {
              super();
              System.out.println("MIN TOO!");
          }
          public int show() {
      
              System.out.println(super.show());
              return super.id;
          }
      
          public static void main(String[] args) {
              min_chapter temp = new min_chapter();
              System.out.println(temp.id);
              System.out.println(temp.show());
          }
      }
      /*
      result:
              CHAPTER3 was created!!!!
              MIN TOO!
              1
              I'm Chapter3
              3
              3
      */
      ```
      
      

4. **this**：是自身的一个对象，代表对象本身，可以理解为：**指向对象本身的一个指针**

   1. 普通的**直接引用**，this 相当于是指向当前对象本身

   2. **形参与成员名字重名，用 this 来区分**：

      - public int GetAge(int age){

        ​        this.age = age;        

        return this.age;             //这里 age 是 GetAge 成员方法的形参，this.age 是 Person 类的成员变量

         }

   3. **引用构造函数**；调用本类中另一种形式的构造函数（应该为构造函数中的第一条语句）

      - 格式：this(参数);

**注意⚠️：**this和 super都指的是对象，所以，均**不可以**在 **static** 环境中使用

5. **类型转换**

   1. 如果是子类对象转换为父类，可进行显式转换或隐式转换：

      Dad = (father) A

      Child = (child) B    //显式转换

   2. 如果是父类对象转换成子类，编译器首先要检查这种转换的可行性，如果可行，则必须进行**显式转换**

6. **多态**：多态性就是一个名称可以对应多种不同的实现方法；对重写的方法，Java根据调用该方法的实例的类型来决定选择哪个方法（c++需要添加virtual）

7. **抽象类（abstract）**：Java 中抽象类表示的是一种继承关系，一个类只能继承一个抽象类，而一个类却可以实现多个接口

   1. 抽象类不能被实例化，必须被继承；抽象方法只有方法的返回值、名称和参数列表，没有方法体，它必须在子类中具体实现该方法
   2. 抽象类没有自己的主体（没有{}包起来的 业务逻辑），跟接口中的方法有点类似。所以没法直接调用抽象方法
   3. 抽象类可以比作不同的交通工具有不同的结果，自行车靠骑，汽车靠发动机运行；因此抽象类只是提供一个 交通工具类（），具体到自行车还是汽车，需要被子类所继承/重写；抽象方法也是同理。因此，抽象方法不可以是static或private，因为抽象方法没有主体，且需要权限访问重写

8. **接口（interface）**：是一个抽象类型，是抽象方法的集合

   1. 接口中的所有方法都是抽象的（可以不写abstract），也没有方法体{}；接口中的所有数据都是静态常量（static,final可以不写）
   2. 一个实现接口的类，必须实现接口内所描述的所有方法，否则就必须声明为抽象类
   3. 接口支持多继承（可以有多个父类）

   - 格式：

     [可见度] interface 接口名称 [extends 其他的接口名] { 

     ​			  // 声明变量        // 抽象方法 

     }

9. **接口实现：**当类实现接口的时候，类要实现接口中所有的方法。否则，类必须声明为抽象的类；类使用implements关键字实现接口。在类声明中，Implements关键字放在class声明后面

   - 格式：`...implements 接口名称[, 其他接口名称, 其他接口名称..., ...] ...`

10. **内部类：**

    1. 成员内部类：成员内部类是最普通的内部类，它的定义为位于另一个类的内部
       - 成员内部类可以无条件访问外部类的所有成员属性和成员方法（包括private成员和静态成员）;　
       
       - 不过要注意的是，当成员内部类拥有和外部类同名的成员变量或者方法时，会发生隐藏现象，即默认情况下访问的是成员内部类的成员。如果要访问外部类的同名成员，需要以下面的形式进行访问：外部类.this.成员变量/方法；
       
       - 在外部类中如果要访问成员内部类的成员，必须先创建一个成员内部类的对象，再通过指向这个对象的引用来访问（需要先new一个内部类）
       
         Test outer = new Test();
       
         Test.inner in = outer.new inner();
       
    2. 局部内部类：
       - 局部内部类是定义在一个方法或者一个作用域里面的类，它和成员内部类的区别在于局部内部类的访问仅限于方法内或者该作用域内
       - 局部内部类就像是方法里面的一个局部变量一样，是**不能有**public、protected、private以及static修饰符
       
    3. 匿名内部类：

       - 可以在定义一个类的同时将它实例化，与局部内部类很相似，区别是它没有类名；如果某个类只需要使用一次，则可以选择采用匿名内部类来简化代码。

       - 前提：必须继承一个父类或实现一个接口,然后继承或重写父类或接口中的方法

       - 格式：father name = new father(){

         ​				public void xxx{

         ​				}

         ​			};

    4. 静态内部类：静态内部类也是定义在另一个类里面的类，只不过在类的前面多了一个关键字static

       - 一旦内部类使用static修饰，这个类就为顶级类；除了写在类内部以外，具有外部类的一切特性
       - 静态内部类可以在内部定义static元素，在构建对象时可以一次性完成（非静态需要先new一个外部类）
       - **内部接口**自动具有static属性，普通类可以直接实现接口

11. **Lambda表达式：**用函数表达式代替常规的代码

    1. 特性：

       - **可选类型声明：**不需要声明参数类型，编译器可以统一识别参数值
       - **可选的参数圆括号：**一个参数无需定义圆括号，但多个参数需要定义圆括号
       - **可选的大括号：**如果主体包含了一个语句，就不需要使用大括号
       - **可选的返回关键字：**如果主体只有一个表达式返回值则编译器会自动返回值，大括号需要指定表达式返回了一个数值

    2. 语法格式：

       (parameters) -> expression      或      (parameters) ->{ statements; return;}

    3. 可以用lambda表达式代替匿名内部类或Runnable接口

    4. 例子：

       - ```java
         Comparator c = (Person p1, Person p2) -> p1.getAge().compareTo(p2.getAge());
         ```

       - ```java
         features.forEach(n -> System.out.println(n));
         ```

12. **泛型:**

    1. 操作的数据类型被指定为一个参数，这种参数类型可以用在类、接口和方法中，分别被称为泛型类、泛型接口、泛型方法

    2. 常见的如**T、E、K、V**等形式的参数常用于表示泛型

    3. **泛型类：**

       - 格式：（泛型的类型参数只能是类类型，不能是简单类型）

       ```Java
       class 类名称 <泛型标识：可以随便写任意标识号，标识指定的泛型的类型>{
         private 泛型标识 /*（成员变量类型）*/ var; 
         .....
         }
       }
       //exp:
       public class Generic<T>{
         private T key;
       }
       ```

    4. **泛型接口:**

       - 格式：

         ```Java
         //定义一个泛型接口
         public interface Generator<T> {
             public T next();
         }
         ```

    5. **泛型方法：**

       1. 泛型方法，是在调用方法的时候指明泛型的具体类型

       - 格式：

         ```Java
         public <T> T genericMethod(Class<T> tClass)throws InstantiationException ,
           IllegalAccessException{
                 T instance = tClass.newInstance();
                 return instance;
         ```

13. **注解：**注解就是对于代码中某些鲜活个体的贴上去的一张标签

    1. **元注解**

       - 元注解是可以注解到注解上的注解，或者说元注解是一种基本注解

       - 元标签有 @Retention、@Documented、@Target、@Inherited、@Repeatable 5 种

         1. **@Retention**

            - 它解释说明了这个注解的的存活时间

            - 它的取值如下：

              1. RetentionPolicy.SOURCE 注解只在源码阶段保留，在编译器进行编译时它将被丢弃忽视。

              2. RetentionPolicy.CLASS 注解只被保留到编译进行的时候，它并不会被加载到 JVM 中。

              3. RetentionPolicy.RUNTIME 注解可以保留到程序运行的时候，它会被加载进入到 JVM 中，所以在程序运行时可以获取到它们。

         2. **@Documented**

            - 它的作用是能够将注解中的元素包含到 Javadoc 中去

         3. **@Target**

            1. 指定了注解运用的地方，当一个注解被 @Target 注解时，这个注解就被限定了运用的场景
            2. @Target 有下面的取值
               - ElementType.ANNOTATION_TYPE 可以给一个注解进行注解
               - ElementType.CONSTRUCTOR 可以给构造方法进行注解
               - ElementType.FIELD 可以给属性进行注解
               - ElementType.LOCAL_VARIABLE 可以给局部变量进行注解
               - ElementType.METHOD 可以给方法进行注解
               - ElementType.PACKAGE 可以给一个包进行注解
               - ElementType.PARAMETER 可以给一个方法内的参数进行注解
               - ElementType.TYPE 可以给一个类型进行注解，比如类、接口、枚举

         4. **@Inherited**

            - Inherited 是继承的意思，但是它并不是说注解本身可以继承，而是说如果一个超类被 @Inherited 注解过的注解进行注解的话，那么如果它的子类没有被任何注解应用的话，那么这个子类就继承了超类的注解
            - 注解 Test 被 @Inherited 修饰，之后类 A 被 Test 注解，类 B 继承 A,类 B 也将拥有 Test 这个注解

         5. **@Repeatable**

            - 可重复的意思，标识某注解可以在同一个声明上使用多次
            - Persons 是一张总的标签，上面贴满了 Person 这种同类型但内容不一样的标签。把 Persons 给一个 SuperMan 贴上，相当于同时给他贴了程序员、产品经理、画家的标签

    2. **注解的属性**

       1. 注解的属性也叫做成员变量。注解只有成员变量，没有方法。注解的成员变量在注解的定义中以“无形参的方法”形式来声明，其方法名定义了该成员变量的名字，其返回值定义了该成员变量的类型

       2. 赋值的方式是在注解的括号内以 value=”” 形式，多个属性之前用 ，隔开  `@<注解名>(<成员名1>=<成员值1>,<成员名1>=<成员值1>,...)`

       3. 需要注意的一种情况是一个注解没有任何属性  public @interface Perform {}

          那么在应用这个注解的时候，括号都可以省略  @Perform

    3. **Java预置的注解**

       1. **@Deprecated**

          这个元素是用来标记过时的元素。编译器在编译阶段遇到这个注解时会发出提醒警告，告诉开发者正在调用一个过时的元素比如过时的方法、过时的类、过时的成员变量

       2. **@Override**

          提示子类要复写父类中被 @Override 修饰的方法

       3. **@SuppressWarnings**

          阻止警告的意思，调用被 @Deprecated 注解的方法后，编译器会警告提醒，而有时候开发者会忽略这种警告，他们可以在调用的地方通过 @SuppressWarnings 达到目的

       4. **@SafeVarargs**

          参数安全类型注解，它的目的是提醒开发者不要用参数做一些不安全的操作,它的存在会阻止编译器产生 unchecked 这样的警告。它是在 Java 1.7 的版本中加入的

       5. **@FunctionalInterface**

          - 函数式接口注解，这个是 Java 1.8 版本引入的新特性。函数式接口 (Functional Interface) 就是一个具有一个方法的普通接口。

          - 进行线程开发中常用的 Runnable 就是一个典型的函数式接口可以看到它就被 @FunctionalInterface 注解

    4. **自定义注解**

       - 格式：public @interface 注解名 {定义体}

### Chapter-6（标准类库）

1. 字符串类：

   1. String的构造：

      - String s = new String("String test"); 

      - String s = "String test";

      - ```java
        char temp_box[] = {'a', 'b', 'c'};   //数组构造
        String temp3 = new String(temp_box);
        ```

   2. 常用方法：

      - **.length()**   求String长度
      - **.equals()**   判断两个字符串是否相同
      - **.compareTo()**   长度相同,从第一位开始比较，如果相同返回0，如果不同则马上返回这两个字符的ascii值的差值; 长度不同,直接返回长度差值
      - **.indexOf()**   由前向后查找指定字符串位置，如果超找到了则返回（第一个字母）位置索引，如果找不到返回-1
      - **.substring(int beginIndex,int endIndex)**   获得的子串是从当前字符串的beginIndex处开始截取到endIndex-1结束所得到的字符串
      - **.replaceAll(String old, String new)**   用new字符串替换old字符串
      - **.trim()**   用于删除字符串的头尾空白符

   3. StringBuffer类：

      - 对字符串进行修改时，需要使用StringBuffer类；StringBuffer类可以多次修改，并且不产生新的未使用对象（因为只对StringBuffer对象本身进行操作）

   4. StringBuilder类：

      - StringBuilder 类在 Java 5 中被提出，它和 StringBuffer 之间的最大不同在于 StringBuilder 的方法不是线程安全的；且相较于StringBuffer，有速度优势

      - ```java
        //代码事例：
        StringBuilder temp = new StringBuilder(10);  //capacity = 10
        temp.append("noob..");
        temp.insert(3,"a");
        ```

      - 常用方法：

        - **.capacity()**   返回当前容量 
        - **.append(String value)**  添加指定字符串到此序列
        - **.insert(int index, String value)**    在index处插入字符串value
        - **.reverse()**   将此字符串用反转形式取代
        - **.delete(int start, int end)**   删除 [start,end) 处的字符串
        - **.replace(int start, int end, String value)**   使用给定value中的字符替换此序列的子字符串中[start,end)的字符

   5. System类：

      - **.currentTimeMillis( )**   返回自1970年1月1日午夜起到现在的时间，时间单位是毫秒
      - **.arraycopy(src, src_start_Pos, dest, dest_start_Pos, length)**   可以将一个任意类型的数组快速地从一个地方复制到另一个地方(这比使用Java中编写的循环要快的多);需要注意的是目标数组相对应位置上的元素会被覆盖掉

   6. Runtime类：

      - Runtime r = new Runtime.getRuntime()； 

        r.totalMemory();   r.freeMemory();         可以用于获取Java虚拟机内部的内存使用

   7. Math类：

      - **.nextInt(int n)**   返回一个[0,n) 的随机整数
      - **.nextDouble();  .nextLong();  .nextBoolean();**   返回一个随机值

   8. Collection集合类：

      - 主要分为3种：Set、Map和List
      - 面向接口编程，先定义接口，再定义实现类
      - 常用方法：
        - .add(); .remove(); .size(); .toarray();

   9. ArrayList类：

      - Iterator：

        ArrayList al = new ArrayList();

        Iterator it = al.iterator();

      - Map;HashMap;Set;HashSet;TreeSet类

### Chapter-7（异常处理）

异常的根类是 **Throwable** ，异常类可以分为**Error**和**Exception**

1. **Error**

   Error通常是无法处理的异常，比如OutOfMemoryError，一般发生这种异常，JVM会选择终止程序

2. **Exception**

   Exception是可以处理的异常，比如NullPointerException、IndexOutOfBoundsException；Exception类的异常包括checked exception和unchecked exception（unchecked exception也称运行时异常RuntimeException，当然这里的运行时异常并不是前面所说的运行期间的异常，只是Java中用运行时异常这个术语来表示，Exception类的异常都是在运行期间发生的）

   - **unchecked exception（非检查异常）**

     也称运行时异常（RuntimeException），比如常见的NullPointerException、IndexOutOfBoundsException。对于运行时异常，java编译器不要求必须进行异常捕获处理或者抛出声明，由程序员自行决定

   - **checked exception（检查异常）**

     也称非运行时异常（运行时异常以外的异常就是非运行时异常），java编译器强制程序员必须进行捕获处理，比如常见的IOExeption和SQLException。对于非运行时异常如果不进行捕获或者抛出声明处理，编译都不会通过

3. **异常的处理**

   1. **Try...catch...finally**

      ```java
      try{
           //try块中放可能发生异常的代码    
        	 //如果执行完try且不发生异常，则接着去执行finally块和finally后面的代码（如果有的话）
        	 //如果发生异常，则尝试去匹配catch块
      }catch(SQLException SQLexception){
           //每一个catch块用于捕获并处理一个特定的异常，或者这异常类型的子类。Java7中可以将多个异常声明在一个catch中
           //catch后面的括号定义了异常类型和异常参数。如果异常与之匹配且是最先匹配到的，则虚拟机将使用这个catch块来处理异常
           //在catch块中可以使用这个块的异常参数来获取异常的相关信息。异常参数是这个catch块中的局部变量，其它块不能访问
           //如果当前try块中发生的异常在后续的所有catch中都没捕获到，则先去执行finally，然后到这个函数的外部caller中去匹配异常处理器
          	//如果try中没有发生异常，则所有的catch块将被忽略
      }catch(Exception exception){
          	//如果同一个try块下的多个catch异常类型有父子关系，应该将子类异常放在前面，父类异常放在后面
      }finally{
            //finally块通常是可选的   
        		//无论异常是否发生，异常是否匹配被处理，finally都会执行
         		//一个try至少要有一个catch块，否则， 至少要有1个finally块。但是finally不是用来处理异常的，finally不会捕获异常
        	  //finally主要做一些清理工作，如流的关闭，数据库连接的关闭等
      }
      ```

      java中，异常处理的任务就是将执行控制流从异常发生的地方转移到能够处理这种异常的地方去。也就是说：当一个函数的某条语句发生异常时，这条语句的后面的语句不会再执行，它失去了焦点。执行流跳转到最近的匹配的异常处理catch代码块去执行，异常被处理完后，执行流会接着在“处理了这个异常的catch代码块”后面接着执行。

   2. **Throws函数**

      - throws是另一种处理异常的方式，它不同于try...catch...finally，throws仅仅是将函数中可能出现的异常向调用者声明，而自己则不具体处理

      - 如果一个方法内部的代码会抛出检查异常（checked exception），而方法自己又没有完全处理掉，则javac保证你必须在方法的签名上使用throws关键字声明这些可能抛出的异常，否则编译不通过
      - 采取这种异常处理的原因可能是：方法本身不知道如何处理这样的异常，或者说让调用者处理更好，调用者需要为可能发生的异常负责

      ```java
      public void foo() throws ExceptionType1 , ExceptionType2 ,ExceptionTypeN
      { 
           //foo内部可以抛出 ExceptionType1 , ExceptionType2 ,ExceptionTypeN 类的异常，或者他们的子类的异常对象
      }
      ```

   3. **Throws和Throw**

      1. throws  是方法可能抛出异常的声明(用在声明方法时，表示该方法可能要抛出异常)  调用者必须做出处理（捕获或继续抛出）

         -   public void doA(int a) **throws** Exception1,Exception3{......}

      2. throw  是语句抛出一个异常

         - throw e;

      3. throws可以单独使用，但throw不能， throw要么和try-catch-finally语句配套使用，要么与throws配套使用。但throws可以单独使用，然后再由处理异常的方法捕获

      4. throw语句用在方法体内,表示抛出异常,由方法体内的语句处理 

         throws语句用在方法声明后面,表示再抛出异常,由调用这个方法的上一级方法中的语句来处理，必须做出处理(捕获或继续声明)

      5. throws主要是声明这个方法会抛出这种类型的异常，使其他地方调用它时知道要捕获这个异常，使得提醒必须做出处理。否则编译是不会通过的
         throw是具体向外抛异常的动作，所以它是抛出一个异常实例

   4. **Finally块**

      1. finally块不管异常是否发生，只要对应的try执行了，则它一定也执行。只有一种方法让finally块不执行：System.exit()。因此finally块通常用来做资源释放操作：关闭文件，关闭数据库连接等等。
      2. 良好的编程习惯是：在try块中打开资源，在finally块中清理释放这些资源
      3. finally块没有处理异常的能力。处理异常的只能是catch块
      4. 在同一try...catch...finally块中 ，如果try中抛出异常，且有匹配的catch块，则先执行catch块，再执行finally块。如果没有catch块匹配，则先执行finally，然后去外面的调用者中寻找合适的catch块
      5. 在同一try...catch...finally块中 ，try发生异常，且匹配的catch块中处理异常时也抛出异常，那么后面的finally也会执行：首先执行finally块，然后去外围调用者中寻找合适的catch块
      6. 在 try块中即便有return，break，continue等改变执行流的语句，finally也会执行

   ⚠️注意：

   1. 当子类重写父类的带有 throws声明的函数时，其throws声明的异常必须在父类异常的可控范围内——用于处理父类的throws方法的异常处理器，必须也适用于子类的这个带throws方法 。这是为了支持多态

   2. Java程序可以是多线程的。每一个线程都是一个独立的执行流，独立的函数调用栈。如果程序只有一个线程，那么没有被任何代码处理的异常 会导致程序终止。如果是多线程的，那么没有被任何代码处理的异常仅仅会导致异常所在的线程结束

      也就是说，Java中的异常是线程独立的，线程的问题应该由线程自己来解决，而不要委托到外部，也不会直接影响到其它线程的执行

   3. finally和return建议

      - 不要在fianlly中使用return

      - 不要在finally中抛出异常

      - 减轻finally的任务，不要在finally中做一些其它的事情，finally块仅仅用来释放资源是最合适的

      - 将尽量将所有的return写在函数的最后面，而不是try ... catch ... finally中

### Chapter-8（输入输出处理）

1. Java流

   标准输入输出，文件的操作，网络上的数据流，字符串流，对象流，zip文件流等等，java中将输入输出抽象称为流，就好像水管，将两个容器连接起来。将数据冲外存中读取到内存中的称为输入流，将数据从内存写入外存中的称为输出流

   流是一个很形象的概念，当程序需要读取数据的时候，就会开启一个通向数据源的流，这个数据源可以是文件，内存，或是网络连接。类似的，当程序需要写入数据的时候，就会开启一个通向目的地的流

   - 流按照流向可以分为两种，输入流InputStream和输出流OutputStream

   - 按照处理数据单元可以分为两种，字节流（8位通用字节流）和字符流（16位Unicode字符流）

     1. **InputStream抽象类** 

         InputStream 为字节输入流，它本身为一个抽象类，必须依靠其子类实现各种功能，此抽象类是表示字节输入流的所有类的超类。 继承自InputStream 的流都是向程序中输入数据的，且数据单位为字节（8bit）

        **Inputstream类中的常用方法**： 

        - **public abstract int read( )：**读取一个byte的数据，返回值是高位补0的int类型值。若返回值=-1说明没有读取到任何字节读取工作结束
        - **public int read(byte b[ ])：**读取b.length个字节的数据放到b数组中。返回值是读取的字节数。该方法实际上是调用下一个方法实现的 
        - **public int read(byte b[ ], int off, int len)：**从输入流中最多读取len个字节的数据，存放到偏移量为off的b数组中
        - **public int available( )：**返回输入流中可以读取的字节数。注意：若输入阻塞，当前线程将被挂起，如果InputStream对象调用这个方法的话，它只会返回0，这个方法必须由继承InputStream类的子类对象调用才有用
        - **public long skip(long n)：**忽略输入流中的n个字节，返回值是实际忽略的字节数, 跳过一些字节来读取 
        - **public int close( ) ：**我们在使用完后，必须对我们打开的流进行关闭

     2. **OutputStream抽象类**

        OutputStream提供了3个write方法来做数据的输出，这个是和InputStream是相对应的

        - **public void write(byte b[ ])：**将参数b中的字节写到输出流。

        - **public void write(byte b[ ], int off, int len) ：**将参数b的从偏移量off开始的len个字节写到输出流。

        - **public abstract void write(int b) ：**先将int转换为byte类型，把低字节写入到输出流中

        - **public void flush( ) :** 将数据缓冲区中数据全部输出，并清空缓冲区

        - **public void close( ) :** 关闭输出流并释放与流相关的系统资源

        *流结束的判断：方法read()的返回值为-1时；readLine()的返回值为null时*

     3. **文件输入流： FileInputStream类**

         FileInputStream可以使用read()方法一次读入一个字节，并以int类型返回，或者是使用read()方法时读入至一个byte数组，byte数组的元素有多少个，就读入多少个字节。在将整个文件读取完成或写入完毕的过程中，这么一个byte数组通常被当作缓冲区，因为这么一个byte数组通常扮演承接数据的中间角色

        ```Java
        import java.io.File;
        import java.io.IOException;
        public class code01 {
            public static void main(String[] args) throws IOException{
                File dir = new File("/Users/calvin/IdeaProjects/test/src/iostream_demon");
                File f1 = new File(dir, "code01.java");
                System.out.println(f1);
                System.out.println("exist :" + f1.exists());
                System.out.println("name :" + f1.getName());
                System.out.println("path :" + f1.getPath());
                System.out.println("absolute path :" + f1.getAbsolutePath());
                System.out.println("parent :" + f1.getParent());
                System.out.println("is a file :" + f1.isFile());
                System.out.println("is a dictionary :" + f1.isDirectory());
                System.out.println("length :" + f1.length());
                File temp_file = File.createTempFile("temp_file01",".tmp");
                System.out.println("absolute path :" + temp_file.getAbsolutePath());
                System.out.println("length :" + temp_file.length());
            }
        }
        ```

     4. **文件输出流:FileOutputStream类**

        用来处理以文件作为数据输出目的数据流；或者说是从内存区读数据入文件

        FileOutputStream类用来处理以文件作为数据输出目的数据流；一个表示文件名的字符串，也可以是File或FileDescriptor对象

        ```Java
        //创建一个文件流对象有两种方法： 
        　　//方式1： 
        　　 File   f=new  File (“d:/myjava/write.txt ");
             FileOutputStream  out= new FileOutputStream (f);
        　　//方式2： 
        　　FileOutputStream out=new FileOutputStream(“d:/myjava/write.txt "); 
        　　//方式3：构造函数将 FileDescriptor()对象作为其参数。 
        　　FileDescriptor() fd=new FileDescriptor(); 
        　　FileOutputStream f2=new FileOutputStream(fd); 
        　　//方式4：构造函数将文件名作为其第一参数，将布尔值作为第二参数。 
        　　FileOutputStream f=new FileOutputStream("d:/abc.txt",true); 
        　　//注意： （1）文件中写数据时，若文件已经存在，则覆盖存在的文件；（2）的读/写操作结束时，应调用close方法关闭流
        ```

     5. **缓冲输入输出流** **BufferedInputStream/ BufferedOutputStream**

        1. 计算机访问外部设备非常耗时。访问外存的频率越高，造成CPU闲置的概率就越大。为了减少访问外存的次数，应该在一次对外设的访问中，读写更多的数据。为此，除了程序和流节点间交换数据必需的读写机制外，还应该增加缓冲机制。缓冲流就是每一个数据流分配一个缓冲区，一个缓冲区就是一个临时存储数据的内存。这样可以减少访问硬盘的次数,提高传输效率

        2. BufferedInputStream: 当向缓冲流写入数据时候，数据先写到缓冲区，待缓冲区写满后，系统一次性将数据发送给输出设备

        3. BufferedOutputStream: 当从向缓冲流读取数据时候，系统先从缓冲区读出数据，待缓冲区为空时，系统再从输入设备读取数据到缓冲区

           - **将文件读入内存：**

             将BufferedInputStream与FileInputStream相接

              FileInputStream in=new FileInputStream( “file1.txt ” );

              BufferedInputStream bin=new BufferedInputStream( in); 

           - **将内存写入文件：**

             将BufferedOutputStream与 FileOutputStream相接

             FileOutputStream out=new FileOutputStream(“file1.txt”);

             BufferedOutputStream bin=new BufferedInputStream(out);

           - **键盘输入流读到内存**

             将BufferedReader与标准的数据流相接 

              InputStreamReader sin=new InputStreamReader (System.in) ；

             BufferedReader bin=new       BufferedReader(sin);

        ```Java
        //缓冲流实现文件复制
        public class code02 {
            public static void main(String[] args) throws IOException {
                int size;
                FileInputStream f = new FileInputStream("/Users/calvin/IdeaProjects/test/src/iostream_demon/code02.java");
                FileOutputStream fout = new FileOutputStream("copy-of-file.txt");
        
                BufferedInputStream bis = new BufferedInputStream(f);
                BufferedOutputStream bos = new BufferedOutputStream(fout);
                System.out.println("Start Copy Process: ");
                int n = f.available();
                byte b[] = new byte[n];
                int count = 0;
                while ((count = bis.read(b, 0, n)) != -1)
                    bos.write(b, 0, n);
                System.out.println("Copy End");
                bis.close();
                bos.flush();
                bos.close();
                f.close();
                fout.flush();
                fout.close();
            }
        }
        ```


### Chapter-09（多线程）

1. **Java中的线程和进程**

   - **线程**：

     1. 进程中负责程序执行的执行单元
     2. 依靠程序执行的顺序控制流，只能使用程序的资源和环境，共享进程的全部资源
     3. 有自己的堆栈和局部变量，没有单独的地址空间
     4. CPU调度和分派的基本单位，持有程序计数器，寄存器，堆栈

     例：*线程与进程相似，但线程是一个比进程更小的执行单位。一个进程在其执行的过程中可以产生多个线程。与进程不同的是同类的多个线程共享进程的**堆**和**方法区**资源，但每个线程有自己的**程序计数器**、**虚拟机栈**和**本地方法栈**，所以系统在产生一个线程，或是在各个线程之间作切换工作时，负担要比进程小得多，也正因为如此，线程也被称为轻量级进程*

   - **进程**：

     1. 系统资源分配和调度的独立单位
     2. 至少包含一个线程
     3. 拥有自己的资源

     例：*进程是程序的一次执行过程，是系统运行程序的基本单位，因此进程是动态的。系统运行一个程序即是一个进程从创建，运行到消亡的过程。在 Java 中，当我们启动 main 函数时其实就是启动了一个 JVM 的进程，而 main 函数所在的线程就是这个进程中的一个线程，也称主线程。在 windows 中通过查看任务管理器的方式，我们就可以清楚看到 window 当前运行的进程（.exe 文件的运行）*

2. **线程与进程的区别**

   - 两者的粒度不同，线程是在一个程序（进程）内
   - 不同进程的代码、内部数据和状态都是完全独立的，而一个进程内的多线程是共享进程的内存空间和系统资源，有可能互相影响
   - 线程本身的数据通常只有寄存器数据，以及一个程序执行时使用的堆栈，所以线程的切换比进程切换的负担要小

3. **Java多线程中的概念**

   - **并行**：多个cpu实例或者多台机器同时执行一段处理逻辑，是真正的同时
   - **并发**：通过cpu调度算法，让用户看上去同时执行，实际上从cpu操作层面不是真正的同时。并发往往在场景中有公用的资源，那么针对这个公用的资源往往产生瓶颈，我们会用TPS或者QPS来反应这个系统的处理能力
   - **线程安全**：经常用来描绘一段代码。指在并发的情况之下，该代码经过多线程使用，线程的调度顺序不影响任何结果。这个时候使用多线程，我们只需要关注系统的内存，cpu是不是够用即可。反过来，线程不安全就意味着线程的调度顺序会影响最终结果，如不加事务的转账代码
   - **同步**：Java中的同步指的是通过人为的控制和调度，保证共享资源的多线程访问成为线程安全，来保证结果的准确。如上面的代码简单加入`@synchronized`关键字。在保证结果准确的同时，提高性能，才是优秀的程序。线程安全的优先级高于性能

4. **线程的状态**

   1. 线程的分类：java中的线程分为两类：1.**守护线程**（如垃圾回收线程，异常处理线程），2.**用户线程**（如主线程）；若JVM中都是守护线程，当前JVM将退出。（形象理解，唇亡齿寒）
   2. 线程的生命周期：

   - **New**: 未启动的线程处于此状态
   - **Runnable**: 在Java虚拟机中执行的线程处于这种状态
   - **Blocked**: 等待monitor锁而被阻塞的线程处于这种状态
   - **Waiting**: 一个线程正在无限期地等待另一个线程执行某个特定的操作，它就处于这种状态
   - **Timed_Waiting**: 等待另一个线程执行操作的线程处于这种状态
   - **Terminated**: 已退出的线程处于这种状态
   - ![img](/Users/calvin/Desktop/CQU/Notes/2.png)

   **可能导致Blocked的情况**:

   1. 调用join()和sleep()方法，sleep()时间结束或被打断，join()中断,IO完成都会回到Runnable状态，等待JVM的调度
   2. 调用wait()，使该线程处于等待池(wait blocked pool),直到notify()/notifyAll()，线程被唤醒被放到锁定池(lock blocked pool )，释放同步锁使线程回到可运行状态（Runnable）
   3. 对Running状态的线程加同步锁(Synchronized)使其进入(lock blocked pool ),同步锁被释放进入可运行状态(Runnable)

5. **每个对象都有的方法**（**机制**）：

   1. **同步机制**：

      1. **同步代码块**

         使用同步监视器（锁）
         Synchronized（同步监视器）{undefined
         //需要被同步的代码
         }
         说明：

         操作共享数据的代码（所有线程共享的数据的操作的代码）（视作卫生间区域（所有人共享的厕所）），即为需要共享的代码（同步代码块，在同步代码块中，相当于是一个单线程，效率低）
         共享数据：多个线程共同操作的数据，比如公共厕所就类比共享数据
         同步监视器（俗称：锁）：任何一个的对象都可以充当锁。（但是为了可读性一般设置英文成lock）当锁住以后只能有一个线程能进去（要求:多个线程必须要共用同一把锁，比如火车上的厕所，同一个标志表示有人）
         Runable天生共享锁，而Thread中需要用static对象或者this关键字或者当前类（window.class）来充当唯一锁

         **代码块**：如下，在多线程环境下，synchronized块中的方法获取了lock实例的monitor，如果实例相同，那么只有一个线程能执行该块内容

         ```java
         public class Thread1 implements Runnable {
            Object lock;
            public void run() {  
                synchronized(lock){
                  ..do something
                }
            }
         }
         ```

      2. **同步方法**

         使用同步方法，对方法进行synchronized关键字修饰
         将同步代码块提取出来成为一个方法，用synchronized关键字修饰此方法。
         对于runnable接口实现多线程，只需要将同步方法用synchronized修饰
         而对于继承自Thread方式，需要将同步方法用static和synchronized修饰，因为对象不唯一（锁不唯一）

         总结：

         ​	1.同步方法仍然涉及到同步监视器，只是不需要我们显示的声明。
         ​	2.非静态的同步方法，同步监视器是this
         静态的同步方法，同步监视器是当前类本身。继承自Thread.class

         **直接用于方法**： 相当于上面代码中用lock来锁定的效果，实际获取的是Thread1类的monitor。更进一步，如果修饰的是static方法，则锁定该类所有实例。

         ```java
         public class Thread1 implements Runnable {
            public synchronized void run() {  
                 ..do something
            }
         }
         ```

      3. **Lock锁**（JDK5.0新增）  与Synchronized的异同

         **相同**：二者都可以解决线程安全问题
         **不同**：synchronized机制在执行完相应的代码逻辑以后，自动的释放同步监视器
         lock需要手动的启动同步（lock（）），同时结束同步也需要手动的实现（unlock（））（同时以为着lock的方式更为灵活）

         **优先使用顺序：**
         **LOCK > 同步代码块 > 同步方法**

   2. **Synchronized, Wait, Notify**

      他们是应用于同步问题的人工线程调度工具。讲其本质，首先就要明确monitor的概念，Java中的每个对象都有一个监视器，来监测并发代码的重入。在非多线程编码时该监视器不发挥作用，反之如果在synchronized 范围内，监视器发挥作用。wait/notify必须存在于synchronized块中。并且，这三个关键字针对的是同一个监视器（某对象的监视器）。这意味着wait之后，其他线程可以进入同步块执行。当某代码并不持有监视器的使用权时（如图中5的状态，即脱离同步块）去wait或notify，会抛出java.lang.IllegalMonitorStateException。也包括在synchronized块中去调用另一个对象的wait/notify，因为不同对象的监视器不同，同样会抛出此异常

      <u>wait，notify需要使用在有锁的地方，也就是需要用synchronize关键字来标识的区域，即使用在同步代码块或者同步方法中，且为了保证wait和notify的区域是同一个锁住的区域，需要用锁来标识，也就是锁要相同的对象来充当</u>

      - **wait**（在进入锁住的区域以后阻塞等待，释放锁让别的线程先进来操作）---- Obj.wait 进入Obj这个锁住的区域的线程把锁交出来原地等待通知（一旦执行此方法，当前线程就进入阻塞状态，并释放同步监视器）
      - **notify**（由于有很多锁住的区域，所以需要将区域用锁来标识，也涉及到锁） ----- Obj.notify 新线程进入Obj这个区域进行操作并唤醒wait的线程（一旦执行此方法，就会唤醒被wait的一个线程，如果有多个线程，就唤醒优先级高的线程）
      - **notifyAll** 一旦执行此方法，就会唤醒所有被wait()的线程

   3. **Synchronized, Wait, Notify结合运用**（典型场景生产者消费者问题）

      ```java
      /**
         * 生产者生产出来的产品交给店员
         */
        public synchronized void produce()
        {
            if(this.product >= MAX_PRODUCT)
            {
                try
                {
                    wait();  
                    System.out.println("产品已满,请稍候再生产");
                }
                catch(InterruptedException e)
                {
                    e.printStackTrace();
                }
                return;
            }
      
            this.product++;
            System.out.println("生产者生产第" + this.product + "个产品.");
            notifyAll();   //通知等待区的消费者可以取出产品了
        }
      
        /**
         * 消费者从店员取产品
         */
        public synchronized void consume()
        {
            if(this.product <= MIN_PRODUCT)
            {
                try 
                {
                    wait(); 
                    System.out.println("缺货,稍候再取");
                } 
                catch (InterruptedException e) 
                {
                    e.printStackTrace();
                }
                return;
            }
      
            System.out.println("消费者取走了第" + this.product + "个产品.");
            this.product--;
            notifyAll();   //通知等待去的生产者可以生产产品了
        }
      ```

6. **线程的死锁问题**

   线程死锁的理解：僵持，谁都不放手，一双筷子，我一只你一只，都等对方放手（死锁，两者都进入阻塞，谁都吃不了饭，进行不了下面吃饭的操作）
   出现死锁以后，不会出现提示，只是所有线程都处于阻塞状态，无法继续

   - 死锁的解决办法：

     > 1.减少同步共享变量
     > 2.采用专门的算法，多个线程之间规定先后执行的顺序，规避死锁问题
     > 3.减少锁的嵌套。

7. **基本线程类（创建线程的三种方法）**

   1. **Thread类**

      1. 相关方法：
         Thread.currentThread().getName()   //获取当前线程的名字

         1. start():1.启动当前线程2.调用线程中的run方法
         2. run():通常需要重写Thread类中的此方法，将创建的线程要执行的操作声明在此方法
         3. currentThread():静态方法，返回执行当前代码的线程
         4. getName():获取当前线程的名字
         5. setName():设置当前线程的名字
         6. yield():主动释放当前线程的执行权
         7. join():在线程中插入执行另一个线程，该线程被阻塞，直到插入执行的线程完全执行完毕以后，该线程才继续执行下去
         8. stop():过时方法。当执行此方法时，强制结束当前线程。
         9. sleep（long millitime）：线程休眠一段时间
         10. isAlive（）：判断当前线程是否存活

         11. interrupt(): 中断线程

      2. **通过继承Thread类本身来创建一个线程**

         创建一个线程的第二种方法是创建一个新的类，该类继承 Thread 类，然后创建一个该类的实例。

         继承类必须重写 run() 方法，该方法是新线程的入口点。它也必须调用 start() 方法才能执行。

         该方法尽管被列为一种多线程实现方式，但是本质上也是实现了 Runnable 接口的一个实例

         ```java
         class ThreadDemo extends Thread {
            private Thread t;
            private String threadName;
            
            ThreadDemo( String name) {
               threadName = name;
               System.out.println("Creating " +  threadName );
            }
            
            public void run() {
               System.out.println("Running " +  threadName );
               try {
                  for(int i = 4; i > 0; i--) {
                     System.out.println("Thread: " + threadName + ", " + i);
                     // 让线程睡眠一会
                     Thread.sleep(50);
                  }
               }catch (InterruptedException e) {
                  System.out.println("Thread " +  threadName + " interrupted.");
               }
               System.out.println("Thread " +  threadName + " exiting.");
            }
            
            public void start () {
               System.out.println("Starting " +  threadName );
               if (t == null) {
                  t = new Thread (this, threadName);
                  t.start ();
               }
            }
         }
          
         public class TestThread {
          
            public static void main(String args[]) {
               ThreadDemo T1 = new ThreadDemo( "Thread-1");
               T1.start();
               
               ThreadDemo T2 = new ThreadDemo( "Thread-2");
               T2.start();
            }   
         }
         ```

      3. **关于中断**：它并不像stop方法那样会中断一个正在运行的线程。线程会不时地检测中断标识位，以判断线程是否应该被中断（中断标识值是否为true）。中断只会影响到wait状态、sleep状态和join状态。被打断的线程会抛出InterruptedException

         - Thread.interrupted()检查当前线程是否发生中断，返回boolean
         - synchronized在获锁的过程中是不能被中断的

         中断是一个状态！interrupt()方法只是将这个状态置为true而已。所以说正常运行的程序不去检测状态，就不会终止，而wait等阻塞方法会去检查并抛出异常。如果在正常运行的程序中添加while(!Thread.interrupted()) ，则同样可以在中断后离开代码体

      4. **注意事项**：写的时候最好要设置线程名称 Thread.name，并设置线程组 ThreadGroup，目的是方便管理。在出现问题的时候，打印线程栈 (jstack -pid) 一眼就可以看出是哪个线程出的问题，这个线程是干什么的

   2. **Runnable类**

      创建一个线程，最简单的方法是创建一个实现 Runnable 接口的类，为了实现 Runnable，一个类只需要执行一个方法调用 run()，声明如下：

      ```java
      public void run()
      ```

      你可以重写该方法，重要的是理解的 run() 可以调用其他方法，使用其他类，并声明变量，就像主线程一样

      在创建一个实现 Runnable 接口的类之后，你可以在类中实例化一个线程对象

      Thread 定义了几个构造方法，下面的这个是我们经常使用的：

      ```java
      Thread(Runnable threadOb,String threadName);
      ```

      这里，threadOb 是一个实现 Runnable 接口的类的实例，并且 threadName 指定新线程的名字

      新线程创建之后，你调用它的 start() 方法它才会运行

      ```java
      void start();
      ```

      下面是一个创建线程并开始让它执行的实例：

      ```java
      class RunnableDemo implements Runnable {
         private Thread t;
         private String threadName;
         
         RunnableDemo( String name) {
            threadName = name;
            System.out.println("Creating " +  threadName );
         }
         
         public void run() {
            System.out.println("Running " +  threadName );
            try {
               for(int i = 4; i > 0; i--) {
                  System.out.println("Thread: " + threadName + ", " + i);
                  // 让线程睡眠一会
                  Thread.sleep(50);
               }
            }catch (InterruptedException e) {
               System.out.println("Thread " +  threadName + " interrupted.");
            }
            System.out.println("Thread " +  threadName + " exiting.");
         }
         
         public void start () {
            System.out.println("Starting " +  threadName );
            if (t == null) {
               t = new Thread (this, threadName);
               t.start ();
            }
         }
      }
       
      public class TestThread {
       
         public static void main(String args[]) {
            RunnableDemo R1 = new RunnableDemo( "Thread-1");
            R1.start();
            
            RunnableDemo R2 = new RunnableDemo( "Thread-2");
            R2.start();
         }   
      }
      ```

   3. **Callable类**

      1. 创建 Callable 接口的实现类，并实现 call() 方法，该 call() 方法将作为线程执行体，并且有返回值。
      2. 创建 Callable 实现类的实例，使用 FutureTask 类来包装 Callable 对象，该 FutureTask 对象封装了该 Callable 对象的 call() 方法的返回值。
      3. 使用 FutureTask 对象作为 Thread 对象的 target 创建并启动新线程。
      4. 调用 FutureTask 对象的 get() 方法来获得子线程执行结束后的返回值。

   ```java
   public class CallableThreadTest implements Callable<Integer> {
       public static void main(String[] args)  
       {  
           CallableThreadTest ctt = new CallableThreadTest();  
           FutureTask<Integer> ft = new FutureTask<>(ctt);  
           for(int i = 0;i < 100;i++)  
           {  
               System.out.println(Thread.currentThread().getName()+" 的循环变量i的值"+i);  
               if(i==20)  
               {  
                   new Thread(ft,"有返回值的线程").start();  
               }  
           }  
           try  
           {  
               System.out.println("子线程的返回值："+ft.get());  
           } catch (InterruptedException e)  
           {  
               e.printStackTrace();  
           } catch (ExecutionException e)  
           {  
               e.printStackTrace();  
           }  
     
       }
       @Override  
       public Integer call() throws Exception  
       {  
           int i = 0;  
           for(;i<100;i++)  
           {  
               System.out.println(Thread.currentThread().getName()+" "+i);  
           }  
           return i;  
       }  
   }
   ```

   4. **三种创建线程方法的对比**：
      1. 采用实现 Runnable、Callable 接口的方式创建多线程时，线程类只是实现了 Runnable 接口或 Callable 接口，还可以继承其他类。
      2. 使用继承 Thread 类的方式创建多线程时，编写简单，如果需要访问当前线程，则无需使用 Thread.currentThread() 方法，直接使用 this 即可获得当前线程。

8. **高级读线程类**

   1. **ThreadLocal类**

      - **用处**：保存线程的独立变量。对一个线程类（继承自Thread)
        当使用ThreadLocal维护变量时，ThreadLocal为每个使用该变量的线程提供独立的变量副本，所以每一个线程都可以独立地改变自己的副本，而不会影响其它线程所对应的副本。常用于用户登录控制，如记录session信息。

      - **实现**：每个Thread都持有一个TreadLocalMap类型的变量（该类是一个轻量级的Map，功能与map一样，区别是桶里放的是entry而不是entry的链表。功能还是一个map。）以本身为key，以目标为value。
        主要方法是get()和set(T a)，set之后在map里维护一个threadLocal -> a，get时将a返回。ThreadLocal是一个特殊的容器。

   2. **原子类（AtomicInteger、AtomicBoolean……）**

      如果使用atomic wrapper class如atomicInteger，或者使用自己保证原子的操作，则等同于synchronized

      ```java
      //返回值为boolean
      AtomicInteger.compareAndSet(int expect,int update)
      ```

      该方法可用于实现乐观锁，考虑文中最初提到的如下场景：a给b付款10元，a扣了10元，b要加10元。此时c给b2元，但是b的加十元代码约为：

      ```java
      if(b.value.compareAndSet(old, value)){
         return ;
      }else{
         //try again
         // if that fails, rollback and log
      }
      ```

      **AtomicReference**
      对于AtomicReference 来讲，也许对象会出现，属性丢失的情况，即oldObject == current，但是oldObject.getPropertyA != current.getPropertyA。
      这时候，AtomicStampedReference就派上用场了。这也是一个很常用的思路，即加上版本号

   3. **Lock类**

      ock: 在java.util.concurrent包内。共有三个实现：

      ```java
      ReentrantLock
      ReentrantReadWriteLock.ReadLock
      ReentrantReadWriteLock.WriteLock
      ```

      主要目的是和synchronized一样， 两者都是为了解决同步问题，处理资源争端而产生的技术。功能类似但有一些区别。

      区别如下：

      ```java
      lock更灵活，可以自由定义多把锁的枷锁解锁顺序（synchronized要按照先加的后解顺序）
      提供多种加锁方案，lock 阻塞式, trylock 无阻塞式, lockInterruptily 可打断式， 还有trylock的带超时时间版本。
      本质上和监视器锁（即synchronized是一样的）
      能力越大，责任越大，必须控制好加锁和解锁，否则会导致灾难。
      和Condition类的结合。
      性能更高，对比如下图：
      ```

      ![img](/Users/calvin/Desktop/CQU/Notes/2-5843264.png)

      synchronized和Lock性能对比

      **ReentrantLock**　　　　
      可重入的意义在于持有锁的线程可以继续持有，并且要释放对等的次数后才真正释放该锁。
      使用方法是：

      1.先new一个实例

      ```java
      static ReentrantLock r=new ReentrantLock();
      2.加锁　　　　　　
      r.lock()或r.lockInterruptibly();
      ```

      此处也是个不同，后者可被打断。当a线程lock后，b线程阻塞，此时如果是lockInterruptibly，那么在调用b.interrupt()之后，b线程退出阻塞，并放弃对资源的争抢，进入catch块。（如果使用后者，必须throw interruptable exception 或catch）　　　　

      3.释放锁　　　

      ```java
      r.unlock()
      ```

      必须做！何为必须做呢，要放在finally里面。以防止异常跳出了正常流程，导致灾难。这里补充一个小知识点，finally是可以信任的：经过测试，哪怕是发生了OutofMemoryError，finally块中的语句执行也能够得到保证。

      **ReentrantReadWriteLock**

      可重入读写锁（读写锁的一个实现）`　`

      ```java
      　ReentrantReadWriteLock lock = new ReentrantReadWriteLock()
      　　ReadLock r = lock.readLock();
      　　WriteLock w = lock.writeLock();
      ```

      两者都有lock,unlock方法。写写，写读互斥；读读不互斥。可以实现并发读的高效线程安全代码

   4. **容器类**

      这里就讨论比较常用的两个：

      ```java
      BlockingQueue
      ConcurrentHashMap
      ```

      **BlockingQueue**
      阻塞队列。该类是java.util.concurrent包下的重要类，通过对Queue的学习可以得知，这个queue是单向队列，可以在队列头添加元素和在队尾删除或取出元素。类似于一个管道，特别适用于先进先出策略的一些应用场景。普通的queue接口主要实现有PriorityQueue（优先队列），有兴趣可以研究

      BlockingQueue在队列的基础上添加了多线程协作的功能：

      ![img](/Users/calvin/Desktop/CQU/Notes/2-20211102165515930.png)

      BlockingQueue

      
      除了传统的queue功能（表格左边的两列）之外，还提供了阻塞接口put和take，带超时功能的阻塞接口offer和poll。put会在队列满的时候阻塞，直到有空间时被唤醒；take在队　列空的时候阻塞，直到有东西拿的时候才被唤醒。用于生产者-消费者模型尤其好用，堪称神器。

      常见的阻塞队列有：

      ```java
      ArrayListBlockingQueue
      LinkedListBlockingQueue
      DelayQueue
      SynchronousQueue
      ```

      **ConcurrentHashMap**
      高效的线程安全哈希map。请对比hashTable , concurrentHashMap, HashMap

   5. **管理类**　

      如果不了解这个类，应该了解前面提到的ExecutorService，开一个自己的线程池非常方便：

      ```java
      ExecutorService e = Executors.newCachedThreadPool();
          ExecutorService e = Executors.newSingleThreadExecutor();
          ExecutorService e = Executors.newFixedThreadPool(3);
          // 第一种是可变大小线程池，按照任务数来分配线程，
          // 第二种是单线程池，相当于FixedThreadPool(1)
          // 第三种是固定大小线程池。
          // 然后运行
          e.execute(new MyRunnableImpl());
      ```

      该类内部是通过ThreadPoolExecutor实现的，掌握该类有助于理解线程池的管理，本质上，他们都是ThreadPoolExecutor类的各种实现版本

### Chapter-10（GUI）

1. Java提供了三个GUI的包

   - java.awt 包 – 主要提供字体/布局管理器

   - javax.swing 包[商业开发常用] – 主要提供各种组件(窗口/按钮/文本框)

   - java.awt.event 包 – 事件处理，后台功能的实现

2. Swing组件：

   1. **顶层容器：**
      - JFrame:一个普通的窗口（绝大多数 Swing 图形界面程序使用 JFrame 作为顶层容器）
      - JDialog:对话框
   2. **中间组件：**
      - JPanel（相当于div）: 一般轻量级面板容器组件(作为JFrame中间容器)
      - JScrollPane: 带滚动条的，可以水平和垂直滚动的面板组件
      - JSplitPane: 分隔面板
      - JTabbedPane: 选项卡面板
      - JLayeredPane: 层级面板
   3. **层级组件：**
      - JLabel: 标签
      - JButton: 按钮
      - JRadioButton: 单选按钮
      - JCheckBox: 复选框
      - JToggleButton: 开关按钮
      - JTextField: 文本框
      - JPasswordField: 密码框
      - JTextArea: 文本区域
      - JComboBox: 下拉列表框
      - JList: 列表
      - JProgressBar: 进度条
      - JSlider: 滑块

3. 相关API

   1. **JFrame组件**

      ```java
      JFrame frame = new JFrame("HelloWorldSwing");                   // 创建及设置窗口
      frame.setDefaultLookAndFeelDecorated(true);                     // 确保一个漂亮的外观风格
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);           //设置默认的关闭窗口
      frame.pack();                                                   // 显示窗口
      frame.setVisible(true);                                         //这个最好放在最后，不然会出现视图看不到的情况
      frame.setBounds(600, 300, 500, 400);                            //设置窗口的x,y位置，窗口大小x,y.
      frame.add(panel)                                                //添加panel面板到容器
      frmIpa.getContentPane().add(panel, BorderLayout.NORTH);         //添加面板到主窗口，布局在北面
      frmIpa.getContentPane().add(scrollPane, BorderLayout.CENTER);   //添加可滚动面板到主窗口，布局在中间
      ```

   2. **Panel组件**

      1. **JPanel**

         ```java
         JPanel panel = new JPanel();                                 //创建面板容器
         panel.add(button);                                           //添加按钮到面板
         ```

      2. **JOptionPane**

         ```java
         JOptionPane.showMessageDialog(panel3, "没有选中任何文件", "提示", JOptionPane.WARNING_MESSAGE); //弹出提示框到panel容器
         ```

      3. **JScrollPane**

         ```java
         JScrollPane scrollPane = new JScrollPane();                   //创建可滚动面板
         scrollPane.setViewportView(textArea);                         //设置面板内容
         ```

   3. 功能组件

      1. **JLabel**

         ```java
          JLabel label = new JLabel("Hello World");                    //添加标签
         ```

      2. **JButton**

         ```java
         JButton button = new JButton("选择文件");                      //创建按钮
         button.addActionListener(new ActionListener() {}              //添加操作按钮后的事件监听器
         ```

      3. **JFileChooser**

         ```java
          jfc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES );            // 设置文件对话框
         jfc.showSaveDialog(frmIpa);                                                // 显示打开的文件对话框
         jfc.getSelectedFile();                                                     // 获取选择器选择的文件
         ```

      4. **JTextArea**

         ```java
         JTextArea textArea = new JTextArea();                                      //创建文本区域
         textArea.setText(content);                                                 //设置内容
         ```

### Chapter-11（网络通信）

0. **网络基础知识**

   1. 两台计算机之间通信的**必备条件**： 

      - **IP地址**：为实现网络中不同计算机之间的通信，每台计算机都必须有一个唯一的标识（32位二进制）

      - **协议**：TCP/IP协议

      - **端口号**：区分一台主机的多个不同应用程序，端口号范围为0-65535，其中0-1023位为系统保留。如：HTTP：80  FTP：21 Telnet：23

        ​      IP地址+端口号组成了所谓的Socket，Socket是网络上运行的程序之间双向通信链路的终结点，是TCP和UDP的基础

   2. **TCP/IP协议**：是目前世界上应用最为广泛的协议，是以TCP和IP为基础的不同层次上多个协议的集合，也成TCP/IP协议族、或TCP/IP协议栈

      ​      	**TCP**：Transmission Control Protocol 传输控制协议

      ​      	**IP**：Internet Protocol 互联网协议

   3. **TCP/IP五层模型**：

      **应用层**：HTTP、FTP、SMTP、Telnet等

      **传输层**：TCP/IP

      **网络层：**定义了IP地址格式

      **数据链路层：**负责接收IP数据包并通过网络发送

      **物理层**：网线、双绞线、网卡等

   4. **Socket套接字**：网络上具有唯一标识的IP地址和端口组合在一起才能构成唯一能识别的标识符套接字；

   5. **Socket的原理机制**：

      - 通信的两端都有Socket

      - 网络通信其实就是Socket间的通信

      - 数据在两个Socket间通过IO传输 

   6. **Java中的网络支持**

      1. **InetAddress**: 用于标识网络上的硬件资源，主要是IP地址
      2. **URL**：统一资源定位符，通过URL可以直接读取或写入网络上的数据
      3. **Sockets**：使用TCP协议实现的网络通信Socket相关的类
      4. **Datagram**: 使用UDP协议，将数据保存在用户数据报中，通过网络进行通信

1. **URL概念**

   - URL 是**统一资源定位符**（Uniform Resource Locator）的简称，它表示 Internet 上某一资源的地址。通过 URL 用户可以访问各种网络资源，比如常见的 WWW 以及 FTP 站点。浏览器可以通过解析给定的 URL 在网络上查找相应的文件或其他资源。

   - 一个URL包括三部分内容：协议，地址，资源
     - 协议指的是获取资源时所使用的应用层协议，如http，ftp，file等;
     - 地址必须是能连接的有效的IP地址或域名;
     - 资源是主机上的任何一个文件，如：http://www.cqu.edu.cn/Channel/CquCampusNews/1/index.htmlURL 的语法格式如下所示：

   ```
   protocol://resourceName
   ```

   - 协议名（protocol）指明获取资源所使用的传输协议，如 HTTP、FTP 和 file 等，资源名（resourceName）则应该是资源的完整地址，包括主机名、端口号、文件名或文件内部的一个引用。下面是一些简单的 URL 示例：

   ```
   http://www.sun.com/    协议名：//主机名
   http://localhost:8080/Test/admin/login.jsp 协议名://机器名：端口号/文件名
   ```

2. **URL类**

   java.net包中的URL类是对统一资源定位符（Uniform Resource Locator）的抽象，一个URL对象存放着一个对应资源的引用。在 java.net 包中包含专门用来处理 URL 的类 URL，可以获得 URL 的相关信息，例如 URL 的协议名和主机名等。下面分别对它的构造方法和常用方法进行介绍

   1. **URL 的构造方法**

   | 构造方法                                                     | 说明                                                      |
   | ------------------------------------------------------------ | --------------------------------------------------------- |
   | public URL (String spec)                                     | 通过一个表示 URL 地址的字符串可以构造一个 URL 对象。      |
   | public URL(URL context,String spec)                          | 使用基本地址和相对 URL 构造一个 URL 对象。                |
   | public URL(String protocol,String host,String file)          | 使用指定的协议、主机名和文件名创建一个 URL 对象。         |
   | public URL(String protocol,String host,int port,String file) | 使用指定的协议、主机名、端口号和文件名创建一个 URL 对象。 |

   2. **URL 的常用方法**

   | 方法                         | 说明                                             |
   | ---------------------------- | ------------------------------------------------ |
   | public String getProtocol()  | 获取该 URL 的协议名。                            |
   | public String getHost()      | 获取该 URL 的主机名。                            |
   | public int getPort()         | 获取该 URL 的端口号，如果没有设置端口，返回 -1。 |
   | public String getFile()      | 获取该 URL 的文件名。                            |
   | public String getRef()       | 获取该 URL 在文件中的相对位置。                  |
   | public String getQuery()     | 获取该 URL 的查询信息。                          |
   | public String getPath()      | 获取该 URL 的路径。                              |
   | public String getAuthority() | 获取该 URL 的权限信息。                          |
   | public String getUserInfo()  | 获得使用者的信息。                               |
   | public String getRef()       | 获得该 URL 的锚点。                              |

   3. **代码demo**

      ```java
      import java.io.IOException;
      import java.io.InputStream;
      import java.net.URL;
      import java.net.URLConnection;
      
      public class URL_Demo {
          public static void main(String[] args) {
              try {
                  URL url = new URL("http://www.baidu.com/");
                  System.out.println("协议：" + url.getProtocol());
                  System.out.println("主机：" + url.getHost());
                  System.out.println("端口：" + url.getPort());
                  InputStream in;
                  URLConnection uc=url.openConnection();
                  in=uc.getInputStream();
                  byte[] b=new byte[1024];
                  int len;
                  while((len=in.read(b))!=-1)
                  {
                      System.out.println(new String(b,0,len));
                  }
                  in.close();
              }
              catch(IOException e)
              {
                  //TODO 自动生成的 catch 块
                  e.printStackTrace();
              }
          }
      }
      ```

      

3. **URLConnection类**

   完成了 URL 的定义，接下来就可以获得 URL 的通信连接。在 java.net 包中，定义了专门的 URLConnection 类来表示与 URL 建立的通信连接，URLConnection 类的对象使用 URL 类的 openConnection() 方法获得

   - URLConnection 类的主要方法：

   | 方法                                             | 说明                                                         |
   | ------------------------------------------------ | ------------------------------------------------------------ |
   | void addRequestProperty(String key,String value) | 添加由键值对指定的一般请求属性。key 指的是用于识别请求的关键字 （例如 accept），value 指的是与该键关联的值。 |
   | void connect()                                   | 打开到此 URL 所引用的资源的通信链接（如果尚未建立这样的链接）。 |
   | Object getConnection()                           | 检索此 URL 链接的内容。                                      |
   | InputStream getInputStream()                     | 返回从此打开的链接读取的输入流。                             |
   | OutputStream getOutputStream()                   | 返回写入到此链接的输出流。                                   |
   | URL getURL()                                     | 返回此 URLConnection 的 URL 字段的值。                       |

4. **InetAddress类**

   InetAddress类用于标识网络上的硬件资源，标识互联网协议(IP)地址，该类没有构造方法。Java通过InetAddress类表示IP地址，用于实现主机名和IP地址之间的转换

   | 方法名                                    | 功能说明                                |
   | ----------------------------------------- | --------------------------------------- |
   | static InetAddress getLocalHost()         | 获得本地主机的InetAddress对象           |
   | static InetAddress getByName(String host) | 获得通过主机名host指定的InetAddress对象 |
   | String getHostAddress()                   | 以带圆点的字符串形式获取IP地址          |
   | String getHostName()                      | 获取主机名字                            |

   ```java
   //获取本机的InetAddress实例
   InetAddress address =InetAddress.getLocalHost();
   address.getHostName();//获取计算机名
   address.getHostAddress();//获取IP地址
   byte[] bytes = address.getAddress();//获取字节数组形式的IP地址,以点分隔的四部分
   
   //获取其他主机的InetAddress实例
   InetAddress address2 =InetAddress.getByName("其他主机名");
   InetAddress address3 =InetAddress.getByName("IP地址");
   ```

5. **TCP**

   1. TCP协议是面向连接的、可靠的、有序的、以字节流的方式发送数据，通过三次握手方式建立连接，形成传输数据的通道，在连接中进行大量数据的传输，效率会稍低

   2. Java中基于TCP协议实现网络通信的类: 客户端的Socket类; 服务器端的ServerSocket类

      ![socket_pic](/Users/calvin/Desktop/CQU/Notes/socket_pic.jpeg)

   3. Socket通信的步骤

      - 创建ServerSocket和Socket

      - 打开连接到Socket的输入/输出流

      - 按照协议对Socket进行读/写操作

      - 关闭输入输出流、关闭Socket

   4. “**三次握手**”

      第一次握手：客户端要和服务端进行通信，客户端向服务器发送一个请求信号
      第二次握手：当服务端接收到客户端的连接请求，此时要给客户端一个确认信息
      第三次握手：当客户端收到了服务端的确认连接信息后，要向服务器发送一个确认信息

   5. **服务器端**：

      - 创建ServerSocket对象，绑定监听端口

      - 通过accept()方法监听客户端请求

      - 连接建立后，通过输入流读取客户端发送的请求信息

      - 通过输出流向客户端发送乡音信息

      - 关闭相关资源

      ```java
      /**
       * 基于TCP协议的Socket通信，实现用户登录，服务端
      */
      //1、创建一个服务器端Socket，即ServerSocket，指定绑定的端口，并监听此端口
      ServerSocket serverSocket =newServerSocket(10086);//1024-65535的某个端口
      //2、调用accept()方法开始监听，等待客户端的连接
      Socket socket = serverSocket.accept();
      //3、获取输入流，并读取客户端信息
      InputStream is = socket.getInputStream();
      InputStreamReader isr =newInputStreamReader(is);
      BufferedReader br =newBufferedReader(isr);
      String info =null;
      while((info=br.readLine())!=null){
      System.out.println("我是服务器，客户端说："+info)；
      }
      socket.shutdownInput();//关闭输入流
      
      //4、获取输出流，响应客户端的请求
      OutputStream os = socket.getOutputStream();
      PrintWriter pw = new PrintWriter(os);
      pw.write("欢迎您！");
      pw.flush();
      
      //5、关闭资源
      pw.close();
      os.close();
      br.close();
      isr.close();
      is.close();
      socket.close();
      serverSocket.close();
      ```

   6. **客户端：**

      - 创建Socket对象，指明需要连接的服务器的地址和端口号
      - 连接建立后，通过输出流想服务器端发送请求信息
      - 通过输入流获取服务器响应的信息
      - 关闭响应资源 

      ```java
      //客户端
      //1、创建客户端Socket，指定服务器地址和端口
      Socket socket =newSocket("localhost",10086);
      //2、获取输出流，向服务器端发送信息
      OutputStream os = socket.getOutputStream();//字节输出流
      PrintWriter pw =newPrintWriter(os);//将输出流包装成打印流
      pw.write("用户名：admin；密码：123");
      pw.flush();
      socket.shutdownOutput();
      //3、获取输入流，并读取服务器端的响应信息
      InputStream is = socket.getInputStream();
      BufferedReader br = new BufferedReader(new InputStreamReader(is));
      String info = null;
      while((info=br.readLine())!null){
       System.out.println("我是客户端，服务器说："+info);
      }
      
      //4、关闭资源
      br.close();
      is.close();
      pw.close();
      os.close();
      socket.close();
      ```

   7. 应用多线程实现服务器与多客户端之间的通信

      - 服务器端创建ServerSocket，循环调用accept()等待客户端连接
      - 客户端创建一个socket并请求和服务器端连接
      - 服务器端接受客户端请求，创建socket与该客户建立专线连接
      - 建立连接的两个socket在一个单独的线程上对话
      - 服务器端继续等待新的连接 

      ```java
      //服务器线程处理
      //和本线程相关的socket
      Socket socket =null;
      //
      public serverThread(Socket socket){
      this.socket = socket;
      }
      
      publicvoid run(){
      //服务器处理代码
      }
      //============================================
      //服务器代码
      ServerSocket serverSocket =newServerSocket(10086);
      Socket socket =null;
      int count =0;//记录客户端的数量
      while(true){
      socket = serverScoket.accept();
      ServerThread serverThread =newServerThread(socket);
       serverThread.start();
       count++;
      System.out.println("客户端连接的数量："+count);
      }
      ```

6. **UDP**

   0. UDP协议（用户数据报协议）是无连接的、不可靠的、无序的,速度快。进行数据传输时，首先将要传输的数据定义成数据报（Datagram），大小限制在64k，在数据报中指明数据索要达到的Socket（主机地址和端口号），然后再将数据报发送出去

   ​	DatagramPacket类:表示数据报包

   ​	DatagramSocket类：进行端到端通信的类

   1. 服务器端实现步骤

      - 创建DatagramSocket，指定端口号

      - 创建DatagramPacket

      - 接受客户端发送的数据信息

      - 读取数据

      ```java
      //服务器端，实现基于UDP的用户登录
      //1、创建服务器端DatagramSocket，指定端口
      DatagramSocket socket =new datagramSocket(10010);
      //2、创建数据报，用于接受客户端发送的数据
      byte[] data =newbyte[1024];//
      DatagramPacket packet =newDatagramPacket(data,data.length);
      //3、接受客户端发送的数据
      socket.receive(packet);//此方法在接受数据报之前会一致阻塞
      //4、读取数据
      String info =newString(data,o,data.length);
      System.out.println("我是服务器，客户端告诉我"+info);
      
      
      //=========================================================
      //向客户端响应数据
      //1、定义客户端的地址、端口号、数据
      InetAddress address = packet.getAddress();
      int port = packet.getPort();
      byte[] data2 = "欢迎您！".geyBytes();
      //2、创建数据报，包含响应的数据信息
      DatagramPacket packet2 = new DatagramPacket(data2,data2.length,address,port);
      //3、响应客户端
      socket.send(packet2);
      //4、关闭资源
      socket.close();
      ```

   2. 客户端实现步骤

      - 定义发送信息

      - 创建DatagramPacket，包含将要发送的信息

      - 创建DatagramSocket

      - 发送数据

      ```java
      //客户端
      //1、定义服务器的地址、端口号、数据
      InetAddress address =InetAddress.getByName("localhost");
      int port =10010;
      byte[] data ="用户名：admin;密码：123".getBytes();
      //2、创建数据报，包含发送的数据信息
      DatagramPacket packet = newDatagramPacket(data,data,length,address,port);
      //3、创建DatagramSocket对象
      DatagramSocket socket =newDatagramSocket();
      //4、向服务器发送数据
      socket.send(packet);
      
      
      //接受服务器端响应数据
      //======================================
      //1、创建数据报，用于接受服务器端响应数据
      byte[] data2 = new byte[1024];
      DatagramPacket packet2 = new DatagramPacket(data2,data2.length);
      //2、接受服务器响应的数据
      socket.receive(packet2);
      String raply = new String(data2,0,packet2.getLenth());
      System.out.println("我是客户端，服务器说："+reply);
      //4、关闭资源
      socket.close();
      ```

   3. **DatagramPacket**

      java.net包中的DatagramPacket类用来表示数据包，构造方法如下：

      ```java
      DatagramPacket(byte[] buf, int length)
      DatagramPacket(byte[] buf, int length, InetAddress address, int port)
      ```

      上述构造方法中，第一种指定了数据包的内存空间和大小，第二种不仅指定了数据包的内存空间和大小，并且指定了数据包的目标地址和端口

   4. **DatagramSocket**

      java.net包中的DatagramSocket类用于表示发送和接受数据包的套接字，构造方法如下：

      ```java
      DatagramSocket()
      DatagramSocket(int port)
      DatagramSocket(int port, InetAddress addr)
      ```

      上述构造方法中，第一种创建数据包套接字并将其绑定到**本地主机上任何可用的端口**，第二种创建数据包套接字并将其绑定到**本地主机上的指定端口**，创建数据包套接字并将其绑定到**指定的本机地址**

7. **MulticastSocket**

   1. MulticastSocket可以将数据报以广播的方式发送到多个客户端。若要使用多点广播，则需要让一个数据报表有一组目标主机地址，当数据包发出去后，整个组的所有主机都能收到该数据报。这样的组其实就是一个多播地址，当客户端需要发送接受广播信息时加入到该组即可

   2. MulticastSocket有点像DatagramSocket，事实上MulticastSocket是DatagramSocket的子类，也就是说MulticastSocket是特殊的DatagramSocket

   3. Java指定了一批特殊的IP地址为多点广播地址，其范围是224.0.0.0至239.255.255.255。每一个多点广播地址都被看做一个组，当客户端需要发送、接收广播信息时，加入到该组即可

   4. MulticastSocket类

      | 构造器                             | 说明                                 |
      | ---------------------------------- | ------------------------------------ |
      | MulticastSocket()                  | 使用本机默认地址，随机端口来创建对象 |
      | MulticastSocket(int ports)         | 使用默认地址，指定端口来创建对象     |
      | MulticastSocket(SocketAddress ads) | 指定IP和端口号来创建对象             |

   5. MulticastSocket类-常用方法

      | 常用方法                            | 说明               | 常用方法                             | 说明                              |
      | ----------------------------------- | ------------------ | ------------------------------------ | --------------------------------- |
      | joinGroup(InetAddress multicastAds) | 加入指定组         | leaveGroup(InetAddress multicastAds) | 离开指定组                        |
      | setInterface()                      | 设置指定的网络接口 | getInterface()                       | 查询MulticastSocket监听的网络接口 |
      | setTimeToLive(int ttl)              | ttl取值范围0-255   | setLoopbackMode(boolean flag)        | 发送的数据是否送回自身            |

      ```java
      public class ServerTest_3 implements Runnable{
       MulticastSocket socket = null;
       byte[] recb = new byte[4096];
       DatagramPacket rec = new DatagramPacket(recb, recb.length);
       DatagramPacket sed = null;
       InetAddress broad = null;
       Scanner sc = null;
       
       public void test() throws IOException {
        	socket = new MulticastSocket(16888);
        	broad = InetAddress.getByName("230.0.0.1");
        	socket.joinGroup(broad);
        	//信息送回自身
        	socket.setLoopbackMode(false);
        	//初始化发送包
        	sed = new DatagramPacket(new byte[0], 0, broad, 16888);
        	new Thread(this).start();
        	sc = new Scanner(System.in);
        	//键盘输入发送消息
        	while(sc.hasNextLine()) {
         		byte[] sedb = sc.nextLine().getBytes();
         		sed.setData(sedb);
         		socket.send(sed);
        	}
       }
       //接受广播信息
       @Override
       public void run() {
        	while(true) {
         	try {
          		socket.receive(rec);
          		//将byte数组转换成Sting类型，并且打印
          		System.out.println(new String(recb, 0, rec.getLength()));
         	} catch (IOException e) {
          		e.printStackTrace();
         	}
        }
       }
       public static void main(String[] args) throws IOException {
        	new ServerTest_3().test();
       }
      }
      ```



⚠️ **对于同一个socket，如果关闭了输出流，则与该输出流关联的socket也会被关闭，所以一般不用关闭流，直接关闭socket即可**

### Chapter-12（JSP和Servlet技术）

1. **JSP**

   https://zhuanlan.zhihu.com/p/42343690

   JSP(Java Server Pages)是Sun公司指定的一种服务器端动态页面技术的组件规范，Jsp是以“.jsp”为后缀的文件，在该文件中主要是html和少量的java 代码。jsp文件在容器中会转换成Servlet中执行。JSP源文件是由安装在Web服务器上的JSP引擎编译执行的。比如Tomcat就是一种JSP引擎。JSP引擎把来自客户端的请求传递给JSP源文件，然后JSP引擎再把对它的响应从JSP源文件传递给客户端

   <img src="/Users/calvin/Desktop/CQU/Notes/截屏2021-11-23 下午4.56.44.png" alt="截屏2021-11-23 下午4.56.44" style="zoom:50%;" />

   <img src="/Users/calvin/Desktop/CQU/Notes/IMG_0081.jpg" alt="IMG_0081" style="zoom:50%;" />

   

2. **Servlet**

   Servlet (Server Applet)是Sun公司指定的一种用来扩展Web服务器功能的组件规范，属于服务器端程序，主要功能在于交互式地浏览和修改数据，生成动态Web内容

   - 是什么：

     - Servlet是一个Java的class，运行在Servlet容器（Tomcat）中
     - 负责接收请求
     - 调用Service处理数据
     - 负责响应数据

     <img src="https://pic2.zhimg.com/80/v2-83c1a7e3ae1e9d236ce568347dd2c3b1_1440w.jpg" alt="img" style="zoom: 50%;" />

   - Servlet部署在容器里，它的生命周期由容器管理

   - Servlet的生命周期概括为以下几个阶段：

     - 装载Servlet：这项操作一般是动态执行的。有些服务器提供了相应的管理功能。可以在启动的时候Servlet就装载Servlet并能够初始化特定的Servlet。
     - 创建一个Servlet实例。
     - 调用Servlet的init()方法。
     - 服务：如果容器接收到对此Servlet的请求，那么它调用Servlet的service()方法。
     - 销毁：实例被销毁，通过调用Servlet的destory()方法来销毁Servlet。 

     <img src="/Users/calvin/Desktop/CQU/Notes/截屏2021-11-24 上午1.05.47.png" alt="截屏2021-11-24 上午1.05.47" style="zoom: 33%;" />

3. **JSP和Servlet**

   ***jsp就是在html里面写java代码，servlet就是在java里面写html代码***

4. **JSP和Servlet的联系和区别**

   - 运行过程
         客户在第一次请求JSP时，请求较慢，因为JSP Engine先把JSP程序转换成servlet代码，接着将它编译成类文件，以后贮存在内存中再次调用速度就快了；访问servlet时，可以直接对其编译好的类文件执行。

   - 使用方式
         要想使用servlet必须把它放在特定位置而且必须对其映射配置；
         jsp可以放在和html同样位置（webapps根目录下或者webapps根目录下的子目录下）而且不需要配置，可以直接使用。

   - 程序组成
         Servlet在Java代码中通过HttpServletResponse对象动态输出HTML内容；
         JSP在静态HTML内容中嵌入Java代码，Java代码被动态执行后生成HTML内容

   - 职能分工
         jsp更侧重于前端页面显示，servlet更侧重于业务逻辑。

   - 本是一家人
         Jsp 本质上是servlet，用jsp实现的页面用servlet也能实现。

5. **MVC**

   - JSP 在Html 中加入了大量的、复杂的业务逻辑，如果后期业务逻辑发生改变，修改jsp 就会捉襟见肘；

   - Servlet 虽然解决了业务逻辑的问题，但是通过字符串拼接的方式生成动态的Html 页面，也会导致代码臃肿，难以维护；

   - MVC(Model-View-Controller)模式就扬长避短，将两者完美结合在一起，它把把软件系统分为三个层次：模型（Model）、视图（View）和控制器（Controller）；
     <img src="https://img-blog.csdn.net/20180430163052691?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3p0MTU3MzI2MjU4Nzg=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70" alt="这里写图片描述" style="zoom:75%;" />

   - 时序图：

     <img src="https://img-blog.csdn.net/20180430163324407?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3p0MTU3MzI2MjU4Nzg=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70" alt="时序图" style="zoom:67%;" />

     1. Web浏览器发送HTTP请求到服务端，被Controller(Servlet)获取并进行处理（例如参数解析、请求转发）

     2. Controller(Servlet)调用核心业务逻辑——Model部分，获得结果

     3. Controller(Servlet)将逻辑处理结果交给View（JSP），动态生成的HTML内容并返回到浏览器显示

6. **JSP和Servlet完整流程**

   <img src="https://pic1.zhimg.com/80/v2-d61a05e5c8823bc6ddc42ccbb19d38e8_1440w.jpg" alt="img" style="zoom:67%;" />

7. **JSP的构成**

   在JSP文件里，主要由模板元素、指令元素、动作元素、脚本元素、声明、表达式、Scriptlets和JSP内建对象组成。

   - **模板元素**
     模板元素是指JSP的静态HTML内容。这些模板元素可以说是网页的框架，它影响页面的结构和美观程度。当客户端请求JSP页面时，它会把这些模板元素一字不变地发送到客户端。
   - **注释** 
     JSP中的注释有三种：HTML注释、隐藏注释和Scriptlets中的注释。
     - HTML注释：在客户端显示一个注释。 
       	<!-- commentInfo [<%=expression %>] --> 
     - 隐藏注释：写在JSP文件中，但不发送给客户端。 
       	<%-- commentInfo --%>
     - Scriptlets中的注释：Java中的注释。
   - **脚本元素** 
     - JSP脚本元素是JSP代码中使用最频繁的元素，它通常是用Java写的脚本代码。 
     - 脚本元素主要包括： 
       - 声明（declaration）
       - 表达式（expression）
       - Scriplets 
   - **指令元素**  
     - 指令用于从JSP发送一个消息到容器上。它用来设置全局变量，声明类、方法和输出内容的类型等。它们并不向客户端产生任何输出，所有的指令都在JSP整个文件范围内有效。 
     - 指令元素使用以下的格式： 
       	<%@ directivename attribute=”value”, attribute=”value” %>  
   - **动作元素** 
     	<prefix:tag attribute=value attribute-list……/> 
     - 容器在处理JSP时，每遇到动作元素，都根据它的标记进行特殊的处理。JSP规范定义了一系列的标准动作，它们用jsp作为前缀。常见的动作元素有：<jsp:forward>、<jsp:getProperty>、<jsp:include>、<jsp:setProperty>、<jsp:useBean>等。

### Chapter-13（Tomcat构建web站点）

### Chapter-14（JDBC）

1.  **JDBC**

   - JDBC全称Java Database Connectivity
   - JDBC可以通过载入不同的数据库的“驱动程序”而与不同的数据库进行连接。

   优点：

   - 使用的驱动不同，即可连接不同的数据库
   - 使用同一套操作来操作不同的数据库
   - 如果每一个数据库java都制订一套连接方式，那么当不同的数据库更新的时候，java也需要更新自己的代码，而使用jdbc，使用同一套代码来操作，使用不同的驱动程序（驱动程序由数据库厂商提供）来连接，这使得可以连接不同的数据库

2. **常用SQL语句**

   - 创建数据库：

     ```java
     CREATE DATABASE [database_name]
     ```

   - 删除数据库：

     ```java
     DROP DATABASE [database_name]
     ```

   - 创建表：

     ```java
     CREATE TABLE table_name ( 
     	column1 DATATYPE [NOT NULL] [NOT NULL PRIMARY KEY], 
     	column2 DATATYPE [NOT NULL], 
     	……
     )
     ```

   - 删除表：

     ```java
     DROP TABLE tableName
     ```

   - 插入一条数据

     ```java
     INSERT INTO tableName (column1, column2, ……)
     VALUES (value1, value2, ……)
     ```

   - 在表中删除数据

     ```java
     DELETE FROM tableName [WHERE ……]
     ```

   - 更新表中的数据

     ```java
     UPDATE tableName SET column1=values1, column2=values2, …… [WHERE ……]
     ```

   - 查询表中的数据

     ```java
     SELECT [ALL | DISTINCT] 目标列表达式[, 目标列表达式] ……
     FROM 基本表或视图[, 基本表或视图] ……
     [WHERE 条件表达式]
     [GROUP BY 列名1 [HAVING 内部函数表达式]]
     [ORDER BY 列名2 [ASC | DESC]]
     ```

3. **JDBC的结构**

   1. JDBC（Java Database Connectivity）是Java程序连接和存取数据库的应用程序接口，它为Java开发者使用数据库提供了统一的操作方式，它由一组Java类和接口组成。JDBC使得开发人员可以使用纯Java的方式来连接数据库，并进行操作。

   2. JDBC由两层组成，上面一层是JDBC API，下面一层是JDBC驱动程序API。

      <img src="/Users/calvin/Desktop/CQU/Notes/截屏2021-11-30 下午5.09.35.png" alt="截屏2021-11-30 下午5.09.35" style="zoom:50%;" />

4. **通过JDBC访问数据库**

   1. **加载JDBC驱动程序**

      - 为了要连接数据库，必须要有相应数据库的JDBC驱动程序，并将驱动程序的.jar文件加入到应用程序的classpath设置中。此后再在程序中通过DriverManager类加载JDBC驱动类。

      -  DriverManager（驱动程序管理器）类是JDBC的管理层，作用于用户和驱动程序之间。DriverManager类跟踪可用的驱动程序，并在数据库和相应驱动程序之间建立连接。 

      - 通过调用Class.forName（）方法将显式地加载驱动程序类。

        ```java
        //1.加载驱动(开发推荐的方式)
        Class.forName("com.mysql.jdbc.Driver");
        // 如果连接的是SQL Server
        Class.forName("com.microsoft.jdbc.sqlserver.SQLServerDriver");
        ```

   2. **建立连接**

      - getConnection()方法将建立在JDBC URL中定义的数据库的Connection连接
      - JDBC的URL的语法如下：
        		jdbc:<子协议>:<子名> 
      - getConnection()方法返回的Connection对象代表与数据库的连接。 
      - Connection接口常用的方法有：close()方法、createStatement()方法 、prepareStatement()方法

      1. URL

         - URL用于标识数据库的位置，程序员通过URL地址告诉JDBC程序连接哪个数据库，URL的写法为：
           - jdbc:mysql:［］//localhost:3306/shen ?参数名：参数值

         - 常用数据库URL地址的写法：
           - Oracle：jdbc:oracle:thin:@localhost:1521:shen
           - SqlServer：jdbc:microsoft:sqlserver://localhost:1433; DatabaseName=shen
           - MySql：jdbc:mysql://localhost:3306/shen

      2. Connection

         - Jdbc程序中的Connection，它用于代表数据库的链接，Collection是数据库编程中最重要的一个对象，客户端与数据库所有交互都是通过connection对象完成的，创建方法为：

           - Connection conn = DriverManager.getConnection(url,user,pass); 

         - 该对象常用方法

           |               方法                |                      描述                      |
           | :-------------------------------: | :--------------------------------------------: |
           |         createStatement()         |       创建向数据库发送sql的statement对象       |
           |       prepareStatement(sql)       | 创建向数据库发送预编译sql的PrepareSatement对象 |
           |         prepareCall(sql)          |    创建执行存储过程的callableStatement对象     |
           | setAutoCommit(boolean autoCommit) |              设置事务是否自动提交              |
           |             commit()              |                在链接上提交事务                |
           |            rollback()             |               在此链接上回滚事务               |

           ```java
           String url = "jdbc:mysql://localhost:3306/shen";
           String username = "shen";
           String password = "Anxin062039";
           Connection conn = null;
           			
           //2.获取与数据库的链接
           conn = DriverManager.getConnection(url, username, password);
           ```

   3. **执行SQL语句**

      - JDBC通过Statement接口向数据库发送SQL语句
      - Statement提供了许多方法，最常用的方法有： execute()方法 、executeQuery()方法 、executeUpdate()方法
      - 有三种Statement对象
        - Statement对象用于执行不带参数的简单SQL语句 
        - PreparedStatement对象用于执行带或者不带参数的预编译SQL语句 
        - CallableStatement对象用于执行对数据库已存储过程的调用

      1. **Statement**

         - Jdbc程序中的Statement对象用于向数据库发送SQL语句，创建方法为：
           - Statement st = conn.createStatement();

         - Statement对象常用方法：

           ```java
           Statement st = null;
           //3.获取用于向数据库发送sql语句的statement
           st = conn.createStatement();
           //4.向数据库发sql
           String sql = "select id,name,password,email,birthday from users";
           st.executeQuery(sql);
           ```

      2. **PreperedStatement**

         PreperedStatement是Statement的孩子，它的实例对象可以通过调用：

         ​	PreperedStatement st = conn.preparedStatement()

         ```java
         PreperedStatement st = null;
         String sql = "select * from users where name=? and password=?";
          
         //3.获取用于向数据库发送sql语句的Preperedstatement
         st = conn.preparedStatement(sql);//在此次传入，进行预编译
         st.setString(1, username);
         st.setString(2, password);
         //4.向数据库发sql
         st.executeQuery();//在这里不需要传入sql
         ```

         比较：相对于Statement对象而言

         - PreperedStatement可以避免SQL注入的问题。
           - 如：String sql="select * from admin where loginname='"+loginName+"' and loginpwd='"+loginPwd+"'";
           - 在应用中：

         ​        -》请输入账号：

         ​             333

         ​        -》请输入密码：

         ​              wer'or'1'='1

         ​		实际上发送：select * from admin where loginname='333' and loginpwd='wer'or'1'='1'，登录成功！

          

         - Statement会使数据库频繁编译SQL，可能造成数据库缓冲区溢出。PreparedStatement 可对SQL进行预编译，从而提高数据库的执行效率。
         - 并且PreperedStatement对于sql中的参数，允许使用占位符的形式进行替换，简化sql语句的编写。

   4. **检索结果**

      - SQL语句发送以后，返回的结果通常存放在一个ResultSet类的对象中，ResultSet对象可以看作是一个表，这个表中包含由SQL返回的列名和相应的值
      - ResultSet对象中维持了一个指向当前行的指针，通过ResultSet.next()方法把当前的指针向下移动一行。最初它位于第一行前，因此第一次调用next()方法将把指针置于第一行上，使它成为当前行。随着每次调用next()方法导致指针向下移动，按照从上到下的次序获取ResultSet行
      - ResultSet提供了检索不同类型字段的方法，最常用的方法 有：getString() 、getFloat() 、getDouble() 、getBlob() 、getClob() 
      - 一系列的getXXX方法提供了获取当前行中某列值的途径，在每一行内，可按任意次序获取列值

   5. **关闭连接,释放资源**

      - 在对象使用完毕后，应当使用close( )方法解除与数据库的连接，并关闭数据库。

      - 例如：con.close();

      - Jdbc程序运行完后，切记要释放程序在运行过程中，创建的那些与数据库进行交互的对象，这些对象通常是ResultSet, Statement和Connection对象。

        注意：为确保资源释放代码能运行，资源释放代码也一定要放在finally语句中。

        ```java
        	if(rs!=null){
        		try{
        			rs.close();
        		}catch (Exception e) {
        			e.printStackTrace();
        		}
        		rs = null;
        	
        	}
        	if(st!=null){
        		try{
        			st.close();
        		}catch (Exception e) {
        			e.printStackTrace();
        		}
        				
        	}	
        	if(conn!=null){
        		try{
        			conn.close();
        		}catch (Exception e) {
        			e.printStackTrace();
        		}
        }
        ```

        

   6. **完整流程**

      <img src="/Users/calvin/Desktop/CQU/Notes/截屏2021-11-30 下午5.15.04.png" alt="截屏2021-11-30 下午5.15.04" style="zoom:50%;" />

5. **事务**

   - 数据库事务（Database Transaction）是数据库操作中的重要概念。它是指作为单个逻辑工作单元执行的一系列操作，要么完全地执行，要么完全地不执行。

   - 事务处理可以确保除非事务性单元内的所有操作都成功完成，否则不会永久更新面向数据的资源。

   - 数据库事务需要满足四个特性：原子性（Atomic）、一致性（Consistency）、隔离性（Isolation）和持久性（Durabiliy），简称为ACID。

   - **示例代码**

     ```java
     Connection conn ;
     try{
       //1获取数据连接
       conn ＝ DriverManager.getConnection();
       //2关闭自动提交的机制
       conn.setAutoCommit(false);
       //3设置事务隔离级别
       …
       //4执行数据库操作
       Statement stmt = conn.createStatement();
       stmt.executeUpdate( "INSERT INTO commodity VALUES(1,'电脑1',2000, '停产') " );
       //5提交事务
       conn.commit();
     }catch(Exception e){
       …
       //6回滚事务
       conn.rollback();
     }finally{
       …
     }
     ```

6. **数据库连接池**

   1. 传统连接方法

      用户每次请求都需要向数据库获得链接，而数据库创建连接通常需要消耗相对较大的资源，创建时间也较长。假设网站一天10万访问量，数据库服务器就需要创建10万次连接，极大的浪费数据库的资源，并且极易造成数据库服务器内存溢出、拓机。

      ![img](https://img-blog.csdn.net/20180728222601898?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzIyMTcyMTMz/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

   2. 数据库连接池

      ![img](https://img-blog.csdn.net/20180728222632985?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzIyMTcyMTMz/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)




### Chapter-15（Java应用开发案例）

## 课外部分

1.遍历Entry对象集合

```java
 public static void main(String[] args) {
        HashMap map = new HashMap();
        map.put("key1", "value1");

        map.put("key2", "value2");

        map.put("key3", "value3");

        Set<Map.Entry<String,String>> set = map.entrySet(); 
   //内部接口，找内部类内部接口，用外部接口外部类调出
        for(Map.Entry<String,String> entry : set){
            System.out.println(entry);
        }
    }

```

### 2. IOStream

#### 2.1 File类（文件读取）

```java
import java.io.File;
import java.io.IOException;
public class code01 {
    public static void main(String[] args) throws IOException{
        File dir = new File("/Users/calvin/IdeaProjects/test/src/iostream_demon");
        File f1 = new File(dir, "code01.java");
        System.out.println(f1);
        System.out.println("exist :" + f1.exists());
        System.out.println("name :" + f1.getName());
        System.out.println("path :" + f1.getPath());
        System.out.println("absolute path :" + f1.getAbsolutePath());
        System.out.println("parent :" + f1.getParent());
        System.out.println("is a file :" + f1.isFile());
        System.out.println("is a dictionary :" + f1.isDirectory());
        System.out.println("length :" + f1.length());
        File temp_file = File.createTempFile("temp_file01",".tmp");
        System.out.println("absolute path :" + temp_file.getAbsolutePath());
        System.out.println("length :" + temp_file.length());
    }
}
```

#### 2.2 File缓冲流实现文件复制

```java
public class code02 {
    public static void main(String[] args) throws IOException {
        int size;
        FileInputStream f = new FileInputStream("/Users/calvin/IdeaProjects/test/src/iostream_demon/code02.java");
        FileOutputStream fout = new FileOutputStream("copy-of-file.txt");

        BufferedInputStream bis = new BufferedInputStream(f);
        BufferedOutputStream bos = new BufferedOutputStream(fout);
        System.out.println("Start Copy Process: ");
        int n = f.available();
        byte b[] = new byte[n];
        int count = 0;
        while ((count = bis.read(b, 0, n)) != -1)
            bos.write(b, 0, n);
        System.out.println("Copy End");

        bis.close();
        bos.flush();
        bos.close();
        f.close();
        fout.flush();
        fout.close();
    }
}
```



### 3. 多线程

#### 3.1 线程与进程

- 进程由操作系统管理，线程是在一个程序（进程）内
- 不同进程代码、数据和状态相互独立，而一个进程内的多线程可以共享内存空间和资源，且可能相互影响
- 线程切换比进程切换的负担小

多线程效率高，适合开发有多种接口的程序

### 4.Junit使用

- junit使用：白盒测试

  ​	1.定义一个测试类（测试用例）

  ​	2.定义测试方法（可独立运行）

  ​	3.给方法加@test

  ​	4.导入junit依赖

- 判定结果：

  ​	红色：失败

  ​	绿色：成功

- 一般使用断言来处理结: Assert.assertEquals(expected, result);
- 补充：
  - @Before：修饰的方法会在测试方法之前被自动执行
  - @After：修饰的方法会在测试方法执行之后执行

### 5.反射

- 反射：将类的各个部分封装为其他对象，这就是反射机制