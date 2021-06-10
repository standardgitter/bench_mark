# bench_mark

run in actions
=================

sqlite3================================================

insert 10000000 rows taken 17867ms, 559690 insert/second 

select 10000000 rows taken 9210ms, 1085776 select/second 


kafka==================================================

Created topic mytopic1.
Topic: mytopic1	TopicId: urBVbX7jQpixdM_GstLZbw	PartitionCount: 1	ReplicationFactor: 1	Configs: segment.bytes=1073741824
	Topic: mytopic1	Partition: 0	Leader: 0	Replicas: 0	Isr: 0
120001 records sent, 24000.2 records/sec (22.89 MB/sec), 1059.5 ms avg latency, 1715.0 ms max latency.
241840 records sent, 48368.0 records/sec (46.13 MB/sec), 701.6 ms avg latency, 995.0 ms max latency.
333104 records sent, 66620.8 records/sec (63.53 MB/sec), 495.9 ms avg latency, 819.0 ms max latency.
364400 records sent, 72880.0 records/sec (69.50 MB/sec), 455.6 ms avg latency, 653.0 ms max latency.
508384 records sent, 101676.8 records/sec (96.97 MB/sec), 323.5 ms avg latency, 421.0 ms max latency.
437536 records sent, 87507.2 records/sec (83.45 MB/sec), 373.1 ms avg latency, 546.0 ms max latency.
425760 records sent, 85152.0 records/sec (81.21 MB/sec), 386.2 ms avg latency, 741.0 ms max latency.
478464 records sent, 95692.8 records/sec (91.26 MB/sec), 341.6 ms avg latency, 530.0 ms max latency.
3000000 records sent, 73233.247895 records/sec (69.84 MB/sec), 438.42 ms avg latency, 1715.00 ms max latency, 361 ms 50th, 914 ms 95th, 1198 ms 99th, 1675 ms 99.9th.
start.time, end.time, data.consumed.in.MB, MB.sec, data.consumed.in.nMsg, nMsg.sec, rebalance.time.ms, fetch.time.ms, fetch.MB.sec, fetch.nMsg.sec
2021-05-12 08:53:26:326, 2021-05-12 08:54:10:025, 2861.0229, 65.4711, 3000000, 68651.4566, 882, 42817, 66.8198, 70065.6281



redis====================================================

PING_INLINE: 0.00
PING_INLINE: 62892.43
PING_INLINE: 65564.88
PING_INLINE: 67206.39
PING_INLINE: 66611.38
PING_INLINE: 68685.85
PING_INLINE: 70077.09 requests per second
PING_BULK: 58597.23
PING_BULK: 68776.40
PING_BULK: 71709.79
PING_BULK: 72847.93
PING_BULK: 73561.56
PING_BULK: 74304.84
PING_BULK: 74349.44 requests per second
SET: 60502.22
SET: 63791.58
SET: 63433.10
SET: 66548.72
SET: 68232.65
SET: 68965.52 requests per second
GET: 33409.09
GET: 49014.70
GET: 58915.71
GET: 60630.83
GET: 61724.07
GET: 64572.33
GET: 66357.00 requests per second
INCR: 61692.30
INCR: 63448.67
INCR: 67194.93
INCR: 69956.75
INCR: 72451.13
INCR: 73853.52
INCR: 74183.98 requests per second
LPUSH: 59146.34
LPUSH: 70951.69
LPUSH: 73245.48
LPUSH: 74397.16
LPUSH: 74791.23
LPUSH: 75187.97 requests per second
RPUSH: 55231.71
RPUSH: 70521.09
RPUSH: 74965.63
RPUSH: 75383.41
RPUSH: 75422.37
RPUSH: 75987.84 requests per second
LPOP: 63785.71
LPOP: 63875.00
LPOP: 70840.47
LPOP: 72624.34
LPOP: 74615.38
LPOP: 75569.62
LPOP: 75815.01 requests per second
RPOP: 59098.45
RPOP: 64898.42
RPOP: 68275.61
RPOP: 71671.26
RPOP: 73406.54
RPOP: 74183.98 requests per second
SADD: 61483.87
SADD: 67469.39
SADD: 66866.78
SADD: 68410.44
SADD: 70715.46
SADD: 70776.62
SADD: 71022.73 requests per second
HSET: 61939.56
HSET: 65701.39
HSET: 68457.48
HSET: 70537.55
HSET: 72007.61
HSET: 72463.77 requests per second
SPOP: 62640.00
SPOP: 66580.00
SPOP: 70643.63
SPOP: 69740.00
SPOP: 70656.20
SPOP: 71896.92
SPOP: 71942.45 requests per second
LPUSH (needed to benchmark LRANGE): 63892.40
LPUSH (needed to benchmark LRANGE): 71220.59
LPUSH (needed to benchmark LRANGE): 74382.98
LPUSH (needed to benchmark LRANGE): 75168.50
LPUSH (needed to benchmark LRANGE): 76556.13
LPUSH (needed to benchmark LRANGE): 77041.60 requests per second
LRANGE_100 (first 100 elements): 53518.52
LRANGE_100 (first 100 elements): 54586.59
LRANGE_100 (first 100 elements): 54225.33
LRANGE_100 (first 100 elements): 54284.38
LRANGE_100 (first 100 elements): 52010.83
LRANGE_100 (first 100 elements): 52481.59
LRANGE_100 (first 100 elements): 52757.46
LRANGE_100 (first 100 elements): 52740.04
LRANGE_100 (first 100 elements): 52798.31 requests per second
LRANGE_300 (first 300 elements): 25254.72
LRANGE_300 (first 300 elements): 25181.82
LRANGE_300 (first 300 elements): 25233.15
LRANGE_300 (first 300 elements): 24737.01
LRANGE_300 (first 300 elements): 24548.68
LRANGE_300 (first 300 elements): 24620.38
LRANGE_300 (first 300 elements): 24316.59
LRANGE_300 (first 300 elements): 24273.70
LRANGE_300 (first 300 elements): 24317.36
LRANGE_300 (first 300 elements): 24381.40
LRANGE_300 (first 300 elements): 24421.83
LRANGE_300 (first 300 elements): 24231.60
LRANGE_300 (first 300 elements): 24205.17
LRANGE_300 (first 300 elements): 24256.79
LRANGE_300 (first 300 elements): 24303.34
LRANGE_300 (first 300 elements): 24305.91
LRANGE_300 (first 300 elements): 24307.24 requests per second
LRANGE_500 (first 450 elements): 17333.33
LRANGE_500 (first 450 elements): 16786.74
LRANGE_500 (first 450 elements): 17332.78
LRANGE_500 (first 450 elements): 17640.33
LRANGE_500 (first 450 elements): 17666.67
LRANGE_500 (first 450 elements): 17753.71
LRANGE_500 (first 450 elements): 17794.12
LRANGE_500 (first 450 elements): 17787.34
LRANGE_500 (first 450 elements): 17801.24
LRANGE_500 (first 450 elements): 17799.83
LRANGE_500 (first 450 elements): 17846.87
LRANGE_500 (first 450 elements): 17745.17
LRANGE_500 (first 450 elements): 17750.24
LRANGE_500 (first 450 elements): 17708.96
LRANGE_500 (first 450 elements): 17620.28
LRANGE_500 (first 450 elements): 17621.14
LRANGE_500 (first 450 elements): 17654.47
LRANGE_500 (first 450 elements): 17688.88
LRANGE_500 (first 450 elements): 17686.44
LRANGE_500 (first 450 elements): 17657.74
LRANGE_500 (first 450 elements): 17659.48
LRANGE_500 (first 450 elements): 17685.28
LRANGE_500 (first 450 elements): 17684.03
LRANGE_500 (first 450 elements): 17686.59 requests per second
LRANGE_600 (first 600 elements): 14490.00
LRANGE_600 (first 600 elements): 14560.00
LRANGE_600 (first 600 elements): 14584.29
LRANGE_600 (first 600 elements): 14537.89
LRANGE_600 (first 600 elements): 14472.50
LRANGE_600 (first 600 elements): 14419.02
LRANGE_600 (first 600 elements): 14339.01
LRANGE_600 (first 600 elements): 14323.77
LRANGE_600 (first 600 elements): 14305.49
LRANGE_600 (first 600 elements): 14245.72
LRANGE_600 (first 600 elements): 14157.86
LRANGE_600 (first 600 elements): 14133.33
LRANGE_600 (first 600 elements): 14174.73
LRANGE_600 (first 600 elements): 14196.47
LRANGE_600 (first 600 elements): 14171.84
LRANGE_600 (first 600 elements): 14197.37
LRANGE_600 (first 600 elements): 14162.59
LRANGE_600 (first 600 elements): 14122.95
LRANGE_600 (first 600 elements): 14079.86
LRANGE_600 (first 600 elements): 14088.95
LRANGE_600 (first 600 elements): 14054.89
LRANGE_600 (first 600 elements): 14057.69
LRANGE_600 (first 600 elements): 14083.17
LRANGE_600 (first 600 elements): 14071.29
LRANGE_600 (first 600 elements): 14040.24
LRANGE_600 (first 600 elements): 14021.82
LRANGE_600 (first 600 elements): 14041.26
LRANGE_600 (first 600 elements): 14059.44
LRANGE_600 (first 600 elements): 14072.62 requests per second
MSET (10 keys): 61233.64
MSET (10 keys): 70319.33
MSET (10 keys): 74461.29
MSET (10 keys): 75584.60
MSET (10 keys): 75732.61
MSET (10 keys): 75700.23 requests per second




nginx===================================================

Server Software:        nginx/1.18.0
Server Hostname:        127.0.0.1
Server Port:            8086

Document Path:          /
Document Length:        10 bytes

Concurrency Level:      100
Time taken for tests:   220.126 seconds
Complete requests:      3000000
Failed requests:        0
Total transferred:      747000000 bytes
HTML transferred:       30000000 bytes
Requests per second:    13628.56 [#/sec] (mean)
Time per request:       7.338 [ms] (mean)
Time per request:       0.073 [ms] (mean, across all concurrent requests)
Transfer rate:          3313.98 [Kbytes/sec] received

nginx keep alive ===================================================
Concurrency Level:      100
Time taken for tests:   150.875 seconds
Complete requests:      3000000
Failed requests:        0
Keep-Alive requests:    2970048
Total transferred:      761850240 bytes
HTML transferred:       30000000 bytes
Requests per second:    19884.04 [#/sec] (mean)
Time per request:       5.029 [ms] (mean)
Time per request:       0.050 [ms] (mean, across all concurrent requests)
Transfer rate:          4931.20 [Kbytes/sec] received



mysql==========================================

myisam == memory
2400 insert/s


innodb autocommit 
1657 insert/second 


innodb batch commit
17997 insert/second 

10client insert 100000 use 16s (innodb autocommit)
use 10client,  6250  insert/second 


ssd==============
MYSQL VERSON IS : 10.5.9-MariaDB
insert myisam 300000 rows taken 12024ms, 24949 insert/second 
count(*)        300000
 The table 't1' is full
insert memory 174604 rows taken 4856ms, 61786 insert/second 
count(*)        174604
insert innodb autocommit 300000 rows taken 128154ms, 2341 insert/second 
count(*)        300000
insert innodb batch commit 300000 rows taken 11040ms, 27174 insert/second 
count(*)        300000

10client insert 100000 use 14s (innodb autocommit)
use 10client,  71000  insert/second 
