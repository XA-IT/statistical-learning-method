# statistical-learning-method
C++ reappearance 
## Chapter 1 统计学习方法概论
统计学习：计算机基于数据构建概率统计模型并运用模型对数据进行预测和分析对一门学科。  
学习：如果一个系统能够通过运用执行某个过程改进它的性能。  
统计学习：监督学习 非监督学习 半监督学习 强化学习  
监督学习： 从给定的、有限的、用于学习的训练数据集合出发  
统计学习三要素：模型 策略 算法  
非概率模型：决策函数表示的模型 概率模型：条件概率表示的模型  
### 损失函数
1. 0-1 loss function 
2. quadratic loss function
3. absolute loss function
4. logarithmic loss function/log-likelyhood loss function  
经验风险（empirical loss）: $R_{emp}(f) = 1/N\sum_{i=1}^{N}L(y_i,f(x_i))$  
经验风险时模型关于训练样本集的平均损失。  
例如，极大似然估计（maximum likelyhood estimation）：模型是条件概率分布，损失函数是对数损失函数。  
结构风险（structural risk minimization）: $R_{srm}(f) = 1/N\sum_{i=1}^NL(y_i, f(x_i))+\lambdaJ(f)$  
结构风险最小化=正则化（regularization），相当于加上$\lambdaJ(f)$正则化项（惩罚项），代表模型的复杂度，模型越复杂，J(f)越大。  
例如，最大后验概率估计(maximum posterior probability)：模型是条件概率分布，损失函数是对数损失函数，模型复杂度由模型的先验概率表示。  
训练误差的大小，可以判断给定的问题是不是一个容易学习的问题。测试误差反映了学习方法对未知的测试数据集的预测能力（泛化能力，generalization ability.  
\*最小二乘法  
交叉验证：将数据集随机分为三部分，训练集，验证集，测试集。  
泛化误差：$R_{emp}(\hat{f}) = E_p[L(Y, \hat{f}(X))] = \int_{XxY}L(y, \hat{f}(x))P(x, y)dxdy$  
本质上是学习到的模型的期望风险。  
\*泛化误差上界的证明  
监督学习方法可以分为生成方法和判别方法，所学到的模型分别称为生成模型和判别模型。 生成模型由朴素贝叶斯法和隐式马尔可夫模型。 典型的判别模型包括k近邻法，感知器，决策树，logistic回归模型，最大熵模型，SVM，提升方法和条件随机场等。  
生成发昂法学习联合概率分布P(X, Y), 然后求出条件概率分布作为预测的模型。 判别方法直接学习决策函数f(X)或者条件概率分布P(Y|X)作为预测模型。  
生成方法可以还原联合概率分布，收敛速度更快，存在隐变量时仍然可以学习。  
判别方法学习准确率更高，简化学习问题。 
评价分类的指标：准确率，精确率，召回率，F1值。

## Chapter 2 感知器

