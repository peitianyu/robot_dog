参考资料:
    https://wiki.friendlyelec.com/wiki/index.php/NanoPi_NEO3/zh

使用系统:
    rk3328-XYZ-friendlycore-lite-focal-6.1-arm64-YYYYMMDD.img.zip
下载工具:
    balenaEtcher

方法:
    下载系统镜像 -> balenaEtcher烧录 -> 将网线连接路由器 -> 查看ip -> 通过 ssh pi@192.168.xxx.xxx 连接, 密码: pi
    也可以使用root用户登录, 密码: fa

    配置静态ip: cat /etc/netplan/01-network-manager-all.yaml
network:
ethernets:
    eth0:
    addresses: [192.168.31.95/24]
    dhcp4: false
    optional: true
    gateway4: 192.168.31.1
    nameservers:
        addresses: [192.168.31.1,114.114.114.114]
version: 2
renderer: NetworkManager
