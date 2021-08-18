#!/bin/bash
make clean 
make fullsubmit
sudo git add .
sudo git commit
sudo git push origin main
echo done!
