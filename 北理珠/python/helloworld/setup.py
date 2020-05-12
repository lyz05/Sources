#!/usr/bin/env python
# coding: utf-8

from setuptools  import setup

setup(
    name='hello-world-20200509',
    version='0.0.2',
    author='lyz05',
    author_email='liuyuanzhe0515@gmail.com',
    description='Hello World Demo',
    packages=['hello_world'],
    install_requires=[],
    keywords = ['Hello', 'World'],
    entry_points={
        'console_scripts': [
            'hello=hello_world:hello',
            'world=hello_world:world'
        ]
    }
)