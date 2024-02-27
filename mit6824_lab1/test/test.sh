#!/bin/bash

bin_dir=../../bin/

mkdir ./test/log

mkdir ./test/zookeeper
cp ./config/zookeeper_profile.yaml ./test/zookeeper
tmux new-session -d -s zk -c "./test/zookeeper/" "./${bin_dir}/imagine_rpc_zookeeper" ./zookeeper_profile.yaml

mkdir ./test/mapper
cp ./test/testfile.txt ./test/mapper/
cp ./config/mapper_profile.yaml ./test/mapper
tmux new-session -d -s mapper -c "./test/mapper" "./${bin_dir}/imagine_mapreduce_mapper" mapper_profile.yaml

mkdir ./test/reducer1
cp ./config/reducer1_profile.yaml ./test/reducer1
tmux new-session -d -s reducer1 -c "./test/reducer1" "./${bin_dir}/imagine_mapreduce_reducer" "reducer1_profile.yaml"

mkdir ./test/reducer2
cp ./config/reducer2_profile.yaml ./test/reducer2
tmux new-session -d -s reducer2 -c "./test/reducer2" "./${bin_dir}/imagine_mapreduce_reducer" "reducer2_profile.yaml"

mkdir ./test/reducer3
cp ./config/reducer3_profile.yaml ./test/reducer3
tmux new-session -d -s reducer3 -c "./test/reducer3" "./${bin_dir}/imagine_mapreduce_reducer" "reducer3_profile.yaml"

mkdir ./test/reducer4
cp ./config/reducer4_profile.yaml ./test/reducer4
tmux new-session -d -s reducer4 -c "./test/reducer4" "./${bin_dir}/imagine_mapreduce_reducer" "reducer4_profile.yaml"

mkdir ./test/reducer5
cp ./config/reducer5_profile.yaml ./test/reducer5
tmux new-session -d -s reducer5 -c "./test/reducer5" "./${bin_dir}/imagine_mapreduce_reducer" "reducer5_profile.yaml"

mkdir ./test/master
cp ./config/master_profile.yaml ./test/master
tmux new-session -d -s master -c "./test/master" "./${bin_dir}/imagine_mapreduce_master" "./master_profile.yaml"