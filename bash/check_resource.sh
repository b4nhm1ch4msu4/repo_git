#!/usr/bin/env bash

cpu_check(){
    cpu_usage=$(top -bn1 | awk '/Cpu/ {print "CPUs usage: " 100-$8 "%"}')
    echo $cpu_usage
}

mem_check(){
    free -h
}

disk_check(){
    df -h | grep 'sda1\|sdb2'
}

case "$1" in
    cpu)cpu_check ;;
    mem)mem_check ;;
    disk)disk_check ;;
    *)
        echo "nothing"
        ;;
esac

