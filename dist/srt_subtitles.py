#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2019-05-02 22:38:28
# @Author  : Lewis Tian (chtian@hust.edu.cn)
# @Link    : https://lewistian.github.io/
# @Version : Python3
# @Description : generate a srt subtitle for premiere pro cc

from glob import glob
import sys

def main(interval):
    for x in glob('*.txt'):
        h, m, s = 0, 0, 0
        data = []
        with open(x, encoding='utf-8') as f:
            lines = f.readlines()
        for index, line in enumerate(lines):
            if s >= 60:
                s -= 60
                m += 1
            if m >= 60:
                m -= 60
                h += 1
            if s + interval >= 60:
                if m + 1 >= 60:
                    srt = f'''{index}\n{h}:{m:02}:{s:02}:000 --> {h+1}:{m+1-60:02}:{s+interval-60:02}:000\n{line}\n'''
                else:
                    srt = f'''{index}\n{h}:{m:02}:{s:02}:000 --> {h}:{m+1:02}:{s+interval-60:02}:000\n{line}\n'''
            else:
                srt = f'''{index}\n{h}:{m:02}:{s:02}:000 --> {h}:{m:02}:{s+interval:02}:000\n{line}\n'''
            s += interval
            print(srt)
            data.append(srt)

        with open(f"{x}.srt", 'w', encoding='utf-8') as f:
            f.write(''.join(data))

if __name__ == '__main__':
    interval = 5
    if len(sys.argv) > 1:
        interval = int(sys.argv[1])
    main(interval)