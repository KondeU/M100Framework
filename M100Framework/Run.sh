# Run shell
# Date:    2017-07-05
# Version: 1.1
# Authors: Deyou Kong <370242479@qq.com>

if [ $# = 1 ] && [ $1 = "-autorun" ]
then cd $(cd "$(dirname "${BASH_SOURCE}")" && pwd)
fi

echo "ubuntu" | sudo -S ./Release/Run.out

