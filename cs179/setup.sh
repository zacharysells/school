#!/bin/bash
cd ListVerse
virtualenv venv -p /usr/bin/python
source venv/bin/activate
pip install -r requirements.txt
cp venv/bin/activate venv/bin/activate2
cat venv/bin/activate2 ../AWScreds.dat > venv/bin/activate
