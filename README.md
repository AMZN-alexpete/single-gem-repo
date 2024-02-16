This is a test repository created for this pull request https://github.com/o3de/o3de/pull/17510
Steps to create were
1. Create a new O3DE gem by running the command:
```
scripts/o3de.bat create-gem -gp c:/single-gem-repo
```
2. Add the remote gem template contents on top
```
scripts/o3de.bat create-from-template -dp c:/single-gem-repo -tp Templates/GemRepo -f
```
3. Git commit and push to an empty GitHub repository
```
cd c:/single-gem-repo
git init .
git checkout -b main
git add .
git commit -sm "Initial commit"
git remote add origin "https://github.com/amzn-alexpete/single-gem-repo"
git push -u origin main
```
