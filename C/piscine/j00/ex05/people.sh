ldapsearch -LLL 'uid=z*' |grep cn: |sed -e 's/cn: //' |sort -f -r
