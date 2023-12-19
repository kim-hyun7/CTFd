FROM ubuntu:22.04


RUN apt-get update
RUN apt-get install xinetd -y
RUN DEBIAN_FRONTEND=noninteractive apt install -y lib32z1

ENV TERM xterm

RUN useradd -ms /bin/bash user

WORKDIR /home/bof1


ADD ./share /home/bof1


RUN chown -R 750 /home/bof1

ADD ./settings/bof1.xinetd /etc/xinetd.d/bof1
ADD ./settings/start.sh /start.sh



CMD ["/usr/sbin/xinetd", "-dontfork"]

