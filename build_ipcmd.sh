#!/bin/bash
git clone https://github.com/nathanweeks/ipcmd ipcmd_repo

cd ipcmd_repo
make
make check

cd ..
mv ipcmd_repo/bin/ipcmd ./
