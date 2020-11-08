#!/usr/bin/env python
"""Scrape readme."""

import os
from pathlib import Path

import requests
from bs4 import BeautifulSoup

patch_names = [d for d in os.listdir(os.getcwd()) if os.path.isdir(d)]

for idn, patch in enumerate(patch_names):
    readme_file = patch + "/README-site"
    if not Path(readme_file).exists():
        URL = "https://dwm.suckless.org/patches/" + patch
        page = requests.get(URL)
        if page.status_code == 404:
            print(f"{URL} does not exists!")
            continue
        soup = BeautifulSoup(page.content, "html.parser")
        readme = soup.find(id="main").text
        with open(readme_file, "w") as file:
            file.write(readme)
