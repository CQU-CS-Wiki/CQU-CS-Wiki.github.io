# CQU-CS-Wiki
这是重庆大学计算机学院的Wiki，由计算机学院学生自发维护。

## 如何修改（非开发者）
直接提交pull requests
## 如何修改（开发者）
### 第一步 配置本地环境
```
pip install mkdocs
```
### 第二步 clone项目
```
git clone 项目地址
```
### 第三步 修改提交
```
mkdocs build
git add .
git commit -m "msg"
git push origin main
mkdocs gh-deploy
```
### optional
```
mkdocs serve #本地运行项目
```

