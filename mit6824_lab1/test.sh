#!/bin/bash

bin_dir = ../bin/

mkdir zookeeper
tmux new-session -d -s zk -c "./zookeeper/" "./${bin_dir}/imagine_mapreduce_zookeeper" 9999

mkdir mapper
tmux new-session -d -s mapper -c "${bin_dir}" "./${bin_dir}/imagine_mapreduce_mapper" 8999

mkdir reducer1
tmux new-session -d -s reducer1 -c "${bin_dir}" "./${bin_dir}/imagine_mapreduce_reducer" 9501

mkdir reducer2
tmux new-session -d -s reducer2 -c "${bin_dir}" "./${bin_dir}/imagine_mapreduce_reducer" 9502

mkdir reducer3
tmux new-session -d -s reducer3 -c "${bin_dir}" "./${bin_dir}/imagine_mapreduce_reducer" 9503

mkdir reducer4
tmux new-session -d -s reducer4 -c "${bin_dir}" "./${bin_dir}/imagine_mapreduce_reducer" 9504

mkdir reducer5
tmux new-session -d -s reducer5 -c "${bin_dir}" "./${bin_dir}/imagine_mapreduce_reducer" 9505

mkdir master
tmux new-session -d -s master -c "${bin_dir}" "./${bin_dir}/imagine_mapreduce_master" 9000