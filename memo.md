第一章 统计学习及监督学习概论  
1.1 统计学习  
学习：一个系统可以通过执行某个过程改进它的性能  
关于数据的基本假设：同类数据具有一定的统计规律性  
随机变量描述数据的特征  
概率分布描述数据的分布规律  
统计机器学习由监督学习，无监督学习，强化学习组成  
统计学习方法：从给定的，有限的，用于学习的训练数据集合出发，假设数据是独立同分布产生的，并且假设要学习的模型属于某个函数的集合，成为假设空间；应用某个评价准则，从假设空间中选取一个最优模型，使它对已知的训练数据及未知的测试数据在给定的评价准则下有最优的预测；最优模型的选取由算法实现  
模型的假设空间中选择模型（学习条件概率分布或决策函数），模型选择的准则为策略，模型学习的方法为算法  

回归问题：输入变量输出变量均为连续变量  
分类问题：输出变量为有限个离散变量  
标注问题：输入变量输出变量均为变量序列  

监督学习 输入输出遵循联合概率分布 训练数据与测试数据依联合概率分布P（X，Y）产生  
监督学习的模型可以是概率模型或非概率模型  
非概率模型指的是直接学习输入空间到输出空间的映射h，学习的过程中基本不涉及概率密度的估计，概率密度的积分等操作，问题的关键在于最优化问题的求解。  
概率模型指出了学习的目的是学出P(x,y)或P(y|x)，但最后都是根据$y = arg max_{y\in{-1, 1}} P(y|x)$来做判别归类  

无监督学习 从无标注数据中学习预测模型 预测模型表示数据的类别，转换或概率 本质是学习数据中的统计规律或潜在结构  
可以实现对数据的聚类，降维（PCA），概率估计（估计数据来自哪些分布 或者分布的组合）  

强化学习 智能系统与环境的连续互动中学习最优行为策略的机器学习问题  
model-based：直接学习马尔科夫决策过程模型，包括转移概率函数和奖励函数  
model-free： 试图求解最优策略或最优价值（基于价值还是策略）  

半监督学习 标注数据和未标注数据学习预测模型  

主动学习 机器不断主动给出实例让教师进行标注，然后利用标注数据学习预测模型  

概率模型是生成模型 非概率模型是判别模型  
概率模型包括决策树，朴素bayes，隐markov，条件随机场，概率潜在语义分析，潜在dirichlet分布，GMM  
非概率模型包括感知器， SVM， k-means，AdaBoost，k近邻，潜在语义分析  
区别在于概率模型一定可以表示为概率分布的形式，非概率模型不一定  

线性模型包括 线性SVM 感知器，k近邻，k-means，潜在语义分析  
非线性模型 核SVM，AdaBoost，神经网络  

参数化模型和非参数化模型 参数化墨西哥假设模型参数的维度固定，模型可以由有现为参数完全刻画 非参数假设维度不固定或者无穷大，随数据量增加而不断增加 现实问题一般为非参数化模型 参数化模型只适合简单的情况  

在线学习 批量学习  

Bayes学习 根据BAYES定理计算后验概率 $p(\theta|D) = \frac{p(\theta)P(D|\theta)}{P(D)}$  
核方法：定义输入空间到高维空间的映射  

期望风险无法计算，因为不知道联合分布  
监督学习两个基本策略： 经验风险最小化（ERM）和结构风险最小化（SRM）  
经验风险最小化：$min_{f\in F} \frac{1}{N} \sum_{i=1}^{N}L(y_i, f(x_i))$  
样本容量少会过拟合，为防止过拟合，用结构风险最小化  
结构风险最小化：$min_{f\in F} \frac{1}{N} \sum_{i=1}^{N}L(y_i, f(x_i)) +  \lambda J(f)$ 惩罚复杂模型  

概率是已知参数，对结果可能性的预测。似然是已知结果，对参数是某个值的可能性预测。  
频率学派的代表：最大似然估计：https://blog.csdn.net/qq_39355550/article/details/81809467  
贝叶斯学派的代表：最大后验概率估计：https://www.jianshu.com/p/9c153d82ba2d  

正则化regularizer 惩罚项penaty term 是结构风险最小化的实现  
正则化的作用：选择经验风险和模型复杂度同时较小的模型  
奥卡姆剃刀原理：在所有可能选择的模型中，能够很好地解释已知数据并且十分简单才是最好的模型，也就是应该选择的模型

交叉验证：随机地将数据机切分成三部分，分别为训练集，验证集和测试集。训练集用来训练模型，验证集用于模型的选择，而测试集用于最终对学习方法的评估。在学习到的不同复杂度的模型，选择对验证集有最小预测误差的模型  
简单交叉验证，S折交叉验证，留一交叉验证  

泛化能力：用测试集误差评估模型的泛化方法  
泛化误差本质上是所学习模型的期望风险
$R_{exp}(\hat{f})=E_{P}[L(Y,\hat{f}(X))] = \int_{\mathcal{X} \times \mathcal{Y}}L(y,\hat{f}(x))P(x,y)dxdy$

泛化误差上界  
对二分类问题，当假设空间是有限个函数的集合$\mathcal{F}={f_1,f_2,f_3,\dots,f_d}$时，对随意一个函数$f\in\mathcal{F}$,至少以概率$1-\delta 0<\delta < 1$,以下不等式成立：  
$R(f)\leq\hat{R}(f) + \epsilon(d,N,\delta)$  
$\epsilon(d,N,\delta) = \sqrt{\frac{1}{2N}(\log d + \log \frac{1}{\delta})}$



