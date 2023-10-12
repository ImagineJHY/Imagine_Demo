# 非开发人员可直接通过make 项目名构建
# 构建项目需要保证安装有:cmake make g++ tmux

# 直接构建需要的项目(这里以mit6824_lab1为例)
make mit_6824_lab1

# 进入到需要构建的项目目录中执行下述命令(这里以mit6824_lab1为例)
cd mit6824_lab1

# 下面所有命令的默认工作路径为项目根目录(如./mit6824_lab1/)

# 第一次初始化时执行
make init

# 切换到thirdparty/Imagine_System的对应分支(这里的例子为Imagine/main分支的最新commit)
cd thirdparty/Imagine_System
git checkout Imagine/main
git pull

# 切换到thirdparty/Imagine_System的对应分支后执行(release版本用Imagine/main分支的最新commit即可)
make prepare

# 构建项目(除非知道自己在做什么, 否则建议先make prepare再make build)
make build

# 一键构建项目
make all

# 一键测试项目(这里以mit6824_lab1为例)
make test_mit6824_lab1