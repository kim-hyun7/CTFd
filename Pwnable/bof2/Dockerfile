FROM ubuntu:20.04


RUN apt-get update
RUN apt-get install xinetd -y
RUN DEBIAN_FRONTEND=noninteractive apt install -y lib32z1

ENV TERM xterm

RUN useradd -ms /bin/bash user

WORKDIR /home/bof2


ADD ./share /home/bof2

RUN echo "#!/bin/bash" > /home/bof2/run.sh && \
    echo "/home/bof2/bof2" >> /home/bof2/run.sh && \
    chmod +x /home/bof2/run.sh

RUN chown -R 750 /home/bof2

ADD ./settings/bof2.xinetd /etc/xinetd.d/bof2



CMD ["/usr/sbin/xinetd", "-dontfork"]

