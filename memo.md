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


