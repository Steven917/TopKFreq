#!/bin/bash
(tr "[:space:][:punct:]" "\n" | sort | grep -v "^$" | uniq -c | sort -nr |
head -20) < 2701.txt
