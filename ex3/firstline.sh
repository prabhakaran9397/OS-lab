#!/bin/s
echo "First line"
sed -n '1, 1p' file2
echo ""

echo "First and Line"
sed -n '1, 1p' file2
tail -1 file2
echo ""

echo "Match Two"
sed -n '/storage/ p' file2 && sed -n '/system admin/ p' file2
echo ""

echo "Match and two lines"
sed -n '/prod/, +2p' file2
echo ""

echo "Till last lines"
sed -n '/database/, $ p' file2
