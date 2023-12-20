FROM ubuntu:22.04


RUN apt-get update
RUN apt-get install xinetd -y
RUN DEBIAN_FRONTEND=noninteractive apt install -y lib32z1

ENV TERM xterm

RUN useradd -ms /bin/bash user

WORKDIR /home/bof1


ADD ./share /home/bof1

RUN echo "#!/bin/bash" > /home/bof1/run.sh && \
    echo "/home/bof1/bof1" >> /home/bof1/run.sh && \
    chmod +x /home/bof1/run.sh

RUN chown -R 750 /home/bof1

ADD ./settings/bof1.xinetd /etc/xinetd.d/bof1



CMD ["/usr/sbin/xinetd", "-dontfork"]

