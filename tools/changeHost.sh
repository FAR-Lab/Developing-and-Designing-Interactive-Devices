#!/bin/bash
# use like this: sh changeHost.sh  NEWHOSTNAME /dir/to/changed/root/
echo "Trying to mount"
mkdir /media/usb
mount $2 /media/usb


echo "About to change Host Name"
cd /media/usb/etc/
OLDHOST=`cat hostname`
NEWHOST=$1 
echo "From $OLDHOST to $NEWHOST"
echo "$NEWHOST" > "hostname"
sed -i "s/127.0.1.1.*$OLDHOST/127.0.1.1\t$NEWHOST/g" hosts
echo "Finished! Unmounting!"
sync

cd ~
umount /media/usb
rm -rf /media/usb
echo "All Done!"

