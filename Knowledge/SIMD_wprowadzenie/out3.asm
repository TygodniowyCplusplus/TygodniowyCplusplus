
main3:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 62 2f 00 00    	pushq  0x2f62(%rip)        # 3f88 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 63 2f 00 00 	bnd jmpq *0x2f63(%rip)        # 3f90 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	pushq  $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmpq 1020 <.plt>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	pushq  $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmpq 1020 <.plt>
    108f:	90                   	nop

Disassembly of section .plt.got:

0000000000001090 <__cxa_finalize@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 2d 2f 00 00 	bnd jmpq *0x2f2d(%rip)        # 3fc8 <__cxa_finalize@GLIBC_2.2.5>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

00000000000010a0 <_ZNSolsEf@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 ed 2e 00 00 	bnd jmpq *0x2eed(%rip)        # 3f98 <_ZNSolsEf@GLIBCXX_3.4>
    10ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010b0 <__cxa_atexit@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 e5 2e 00 00 	bnd jmpq *0x2ee5(%rip)        # 3fa0 <__cxa_atexit@GLIBC_2.2.5>
    10bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010c0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	f2 ff 25 dd 2e 00 00 	bnd jmpq *0x2edd(%rip)        # 3fa8 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GLIBCXX_3.4>
    10cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010d0 <_ZNSolsEPFRSoS_E@plt>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	f2 ff 25 d5 2e 00 00 	bnd jmpq *0x2ed5(%rip)        # 3fb0 <_ZNSolsEPFRSoS_E@GLIBCXX_3.4>
    10db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010e0 <__stack_chk_fail@plt>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	f2 ff 25 cd 2e 00 00 	bnd jmpq *0x2ecd(%rip)        # 3fb8 <__stack_chk_fail@GLIBC_2.4>
    10eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010f0 <_ZNSt8ios_base4InitC1Ev@plt>:
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	f2 ff 25 c5 2e 00 00 	bnd jmpq *0x2ec5(%rip)        # 3fc0 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    10fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001100 <_start>:
    1100:	f3 0f 1e fa          	endbr64 
    1104:	31 ed                	xor    %ebp,%ebp
    1106:	49 89 d1             	mov    %rdx,%r9
    1109:	5e                   	pop    %rsi
    110a:	48 89 e2             	mov    %rsp,%rdx
    110d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1111:	50                   	push   %rax
    1112:	54                   	push   %rsp
    1113:	4c 8d 05 56 05 00 00 	lea    0x556(%rip),%r8        # 1670 <__libc_csu_fini>
    111a:	48 8d 0d df 04 00 00 	lea    0x4df(%rip),%rcx        # 1600 <__libc_csu_init>
    1121:	48 8d 3d c1 00 00 00 	lea    0xc1(%rip),%rdi        # 11e9 <main>
    1128:	ff 15 b2 2e 00 00    	callq  *0x2eb2(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    112e:	f4                   	hlt    
    112f:	90                   	nop

0000000000001130 <deregister_tm_clones>:
    1130:	48 8d 3d d9 2e 00 00 	lea    0x2ed9(%rip),%rdi        # 4010 <__TMC_END__>
    1137:	48 8d 05 d2 2e 00 00 	lea    0x2ed2(%rip),%rax        # 4010 <__TMC_END__>
    113e:	48 39 f8             	cmp    %rdi,%rax
    1141:	74 15                	je     1158 <deregister_tm_clones+0x28>
    1143:	48 8b 05 8e 2e 00 00 	mov    0x2e8e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    114a:	48 85 c0             	test   %rax,%rax
    114d:	74 09                	je     1158 <deregister_tm_clones+0x28>
    114f:	ff e0                	jmpq   *%rax
    1151:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1158:	c3                   	retq   
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <register_tm_clones>:
    1160:	48 8d 3d a9 2e 00 00 	lea    0x2ea9(%rip),%rdi        # 4010 <__TMC_END__>
    1167:	48 8d 35 a2 2e 00 00 	lea    0x2ea2(%rip),%rsi        # 4010 <__TMC_END__>
    116e:	48 29 fe             	sub    %rdi,%rsi
    1171:	48 89 f0             	mov    %rsi,%rax
    1174:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1178:	48 c1 f8 03          	sar    $0x3,%rax
    117c:	48 01 c6             	add    %rax,%rsi
    117f:	48 d1 fe             	sar    %rsi
    1182:	74 14                	je     1198 <register_tm_clones+0x38>
    1184:	48 8b 05 65 2e 00 00 	mov    0x2e65(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    118b:	48 85 c0             	test   %rax,%rax
    118e:	74 08                	je     1198 <register_tm_clones+0x38>
    1190:	ff e0                	jmpq   *%rax
    1192:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1198:	c3                   	retq   
    1199:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011a0 <__do_global_dtors_aux>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	80 3d 85 2f 00 00 00 	cmpb   $0x0,0x2f85(%rip)        # 4130 <completed.8055>
    11ab:	75 2b                	jne    11d8 <__do_global_dtors_aux+0x38>
    11ad:	55                   	push   %rbp
    11ae:	48 83 3d 12 2e 00 00 	cmpq   $0x0,0x2e12(%rip)        # 3fc8 <__cxa_finalize@GLIBC_2.2.5>
    11b5:	00 
    11b6:	48 89 e5             	mov    %rsp,%rbp
    11b9:	74 0c                	je     11c7 <__do_global_dtors_aux+0x27>
    11bb:	48 8b 3d 46 2e 00 00 	mov    0x2e46(%rip),%rdi        # 4008 <__dso_handle>
    11c2:	e8 c9 fe ff ff       	callq  1090 <__cxa_finalize@plt>
    11c7:	e8 64 ff ff ff       	callq  1130 <deregister_tm_clones>
    11cc:	c6 05 5d 2f 00 00 01 	movb   $0x1,0x2f5d(%rip)        # 4130 <completed.8055>
    11d3:	5d                   	pop    %rbp
    11d4:	c3                   	retq   
    11d5:	0f 1f 00             	nopl   (%rax)
    11d8:	c3                   	retq   
    11d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011e0 <frame_dummy>:
    11e0:	f3 0f 1e fa          	endbr64 
    11e4:	e9 77 ff ff ff       	jmpq   1160 <register_tm_clones>

00000000000011e9 <main>:
    11e9:	f3 0f 1e fa          	endbr64 
    11ed:	4c 8d 54 24 08       	lea    0x8(%rsp),%r10
    11f2:	48 83 e4 e0          	and    $0xffffffffffffffe0,%rsp
    11f6:	41 ff 72 f8          	pushq  -0x8(%r10)
    11fa:	55                   	push   %rbp
    11fb:	48 89 e5             	mov    %rsp,%rbp
    11fe:	41 52                	push   %r10
    1200:	48 81 ec 68 03 00 00 	sub    $0x368,%rsp
    1207:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    120e:	00 00 
    1210:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1214:	31 c0                	xor    %eax,%eax
    1216:	c7 85 a4 fc ff ff 01 	movl   $0x1,-0x35c(%rbp)
    121d:	00 00 00 
    1220:	48 8d 85 d0 fd ff ff 	lea    -0x230(%rbp),%rax
    1227:	48 89 c7             	mov    %rax,%rdi
    122a:	e8 13 03 00 00       	callq  1542 <_ZSt3endIfLm32EEPT_RAT0__S0_>
    122f:	48 89 c1             	mov    %rax,%rcx
    1232:	48 8d 95 a4 fc ff ff 	lea    -0x35c(%rbp),%rdx
    1239:	48 8d 85 d0 fd ff ff 	lea    -0x230(%rbp),%rax
    1240:	48 89 ce             	mov    %rcx,%rsi
    1243:	48 89 c7             	mov    %rax,%rdi
    1246:	e8 0d 03 00 00       	callq  1558 <_ZSt4fillIPfiEvT_S1_RKT0_>
    124b:	c7 85 a4 fc ff ff 02 	movl   $0x2,-0x35c(%rbp)
    1252:	00 00 00 
    1255:	48 8d 85 50 fe ff ff 	lea    -0x1b0(%rbp),%rax
    125c:	48 89 c7             	mov    %rax,%rdi
    125f:	e8 de 02 00 00       	callq  1542 <_ZSt3endIfLm32EEPT_RAT0__S0_>
    1264:	48 89 c1             	mov    %rax,%rcx
    1267:	48 8d 95 a4 fc ff ff 	lea    -0x35c(%rbp),%rdx
    126e:	48 8d 85 50 fe ff ff 	lea    -0x1b0(%rbp),%rax
    1275:	48 89 ce             	mov    %rcx,%rsi
    1278:	48 89 c7             	mov    %rax,%rdi
    127b:	e8 d8 02 00 00       	callq  1558 <_ZSt4fillIPfiEvT_S1_RKT0_>
    1280:	c7 85 a4 fc ff ff 03 	movl   $0x3,-0x35c(%rbp)
    1287:	00 00 00 
    128a:	48 8d 85 d0 fe ff ff 	lea    -0x130(%rbp),%rax
    1291:	48 89 c7             	mov    %rax,%rdi
    1294:	e8 a9 02 00 00       	callq  1542 <_ZSt3endIfLm32EEPT_RAT0__S0_>
    1299:	48 89 c1             	mov    %rax,%rcx
    129c:	48 8d 95 a4 fc ff ff 	lea    -0x35c(%rbp),%rdx
    12a3:	48 8d 85 d0 fe ff ff 	lea    -0x130(%rbp),%rax
    12aa:	48 89 ce             	mov    %rcx,%rsi
    12ad:	48 89 c7             	mov    %rax,%rdi
    12b0:	e8 a3 02 00 00       	callq  1558 <_ZSt4fillIPfiEvT_S1_RKT0_>
    12b5:	c7 85 a4 fc ff ff 00 	movl   $0x0,-0x35c(%rbp)
    12bc:	00 00 00 
    12bf:	48 8d 85 50 ff ff ff 	lea    -0xb0(%rbp),%rax
    12c6:	48 89 c7             	mov    %rax,%rdi
    12c9:	e8 74 02 00 00       	callq  1542 <_ZSt3endIfLm32EEPT_RAT0__S0_>
    12ce:	48 89 c1             	mov    %rax,%rcx
    12d1:	48 8d 95 a4 fc ff ff 	lea    -0x35c(%rbp),%rdx
    12d8:	48 8d 85 50 ff ff ff 	lea    -0xb0(%rbp),%rax
    12df:	48 89 ce             	mov    %rcx,%rsi
    12e2:	48 89 c7             	mov    %rax,%rdi
    12e5:	e8 6e 02 00 00       	callq  1558 <_ZSt4fillIPfiEvT_S1_RKT0_>
    12ea:	48 8d 85 d0 fd ff ff 	lea    -0x230(%rbp),%rax
    12f1:	48 89 85 b0 fc ff ff 	mov    %rax,-0x350(%rbp)
    12f8:	48 8d 85 50 fe ff ff 	lea    -0x1b0(%rbp),%rax
    12ff:	48 89 85 b8 fc ff ff 	mov    %rax,-0x348(%rbp)
    1306:	48 8d 85 d0 fe ff ff 	lea    -0x130(%rbp),%rax
    130d:	48 89 85 c0 fc ff ff 	mov    %rax,-0x340(%rbp)
    1314:	48 8d 85 50 ff ff ff 	lea    -0xb0(%rbp),%rax
    131b:	48 89 85 c8 fc ff ff 	mov    %rax,-0x338(%rbp)
    1322:	c7 85 a8 fc ff ff 00 	movl   $0x0,-0x358(%rbp)
    1329:	00 00 00 
    132c:	83 bd a8 fc ff ff 03 	cmpl   $0x3,-0x358(%rbp)
    1333:	0f 8f 08 01 00 00    	jg     1441 <main+0x258>
    1339:	8b 85 a8 fc ff ff    	mov    -0x358(%rbp),%eax
    133f:	48 98                	cltq   
    1341:	48 c1 e0 05          	shl    $0x5,%rax
    1345:	48 89 c2             	mov    %rax,%rdx
    1348:	48 8b 85 b8 fc ff ff 	mov    -0x348(%rbp),%rax
    134f:	48 01 d0             	add    %rdx,%rax
    1352:	c5 fc 28 00          	vmovaps (%rax),%ymm0
    1356:	8b 85 a8 fc ff ff    	mov    -0x358(%rbp),%eax
    135c:	48 98                	cltq   
    135e:	48 c1 e0 05          	shl    $0x5,%rax
    1362:	48 89 c2             	mov    %rax,%rdx
    1365:	48 8b 85 b0 fc ff ff 	mov    -0x350(%rbp),%rax
    136c:	48 01 d0             	add    %rdx,%rax
    136f:	c5 fc 28 08          	vmovaps (%rax),%ymm1
    1373:	c5 fc 29 8d 90 fd ff 	vmovaps %ymm1,-0x270(%rbp)
    137a:	ff 
    137b:	c5 fc 29 85 b0 fd ff 	vmovaps %ymm0,-0x250(%rbp)
    1382:	ff 
    1383:	c5 fc 28 85 90 fd ff 	vmovaps -0x270(%rbp),%ymm0
    138a:	ff 
    138b:	c5 fc 59 85 b0 fd ff 	vmulps -0x250(%rbp),%ymm0,%ymm0
    1392:	ff 
    1393:	c5 fc 29 85 d0 fc ff 	vmovaps %ymm0,-0x330(%rbp)
    139a:	ff 
    139b:	8b 85 a8 fc ff ff    	mov    -0x358(%rbp),%eax
    13a1:	48 98                	cltq   
    13a3:	48 c1 e0 05          	shl    $0x5,%rax
    13a7:	48 89 c2             	mov    %rax,%rdx
    13aa:	48 8b 85 c0 fc ff ff 	mov    -0x340(%rbp),%rax
    13b1:	48 01 d0             	add    %rdx,%rax
    13b4:	c5 fc 28 00          	vmovaps (%rax),%ymm0
    13b8:	c5 fc 28 8d d0 fc ff 	vmovaps -0x330(%rbp),%ymm1
    13bf:	ff 
    13c0:	c5 fc 29 8d 50 fd ff 	vmovaps %ymm1,-0x2b0(%rbp)
    13c7:	ff 
    13c8:	c5 fc 29 85 70 fd ff 	vmovaps %ymm0,-0x290(%rbp)
    13cf:	ff 
    13d0:	c5 fc 28 85 50 fd ff 	vmovaps -0x2b0(%rbp),%ymm0
    13d7:	ff 
    13d8:	c5 fc 58 85 70 fd ff 	vaddps -0x290(%rbp),%ymm0,%ymm0
    13df:	ff 
    13e0:	c5 fc 29 85 f0 fc ff 	vmovaps %ymm0,-0x310(%rbp)
    13e7:	ff 
    13e8:	8b 85 a8 fc ff ff    	mov    -0x358(%rbp),%eax
    13ee:	48 98                	cltq   
    13f0:	48 c1 e0 05          	shl    $0x5,%rax
    13f4:	48 89 c2             	mov    %rax,%rdx
    13f7:	48 8b 85 c8 fc ff ff 	mov    -0x338(%rbp),%rax
    13fe:	48 01 d0             	add    %rdx,%rax
    1401:	c5 fc 28 85 d0 fc ff 	vmovaps -0x330(%rbp),%ymm0
    1408:	ff 
    1409:	c5 fc 29 85 10 fd ff 	vmovaps %ymm0,-0x2f0(%rbp)
    1410:	ff 
    1411:	c5 fc 28 85 f0 fc ff 	vmovaps -0x310(%rbp),%ymm0
    1418:	ff 
    1419:	c5 fc 29 85 30 fd ff 	vmovaps %ymm0,-0x2d0(%rbp)
    1420:	ff 
    1421:	c5 fc 28 85 10 fd ff 	vmovaps -0x2f0(%rbp),%ymm0
    1428:	ff 
    1429:	c5 fc 58 85 30 fd ff 	vaddps -0x2d0(%rbp),%ymm0,%ymm0
    1430:	ff 
    1431:	c5 fc 29 00          	vmovaps %ymm0,(%rax)
    1435:	83 85 a8 fc ff ff 01 	addl   $0x1,-0x358(%rbp)
    143c:	e9 eb fe ff ff       	jmpq   132c <main+0x143>
    1441:	48 8d 35 bd 0b 00 00 	lea    0xbbd(%rip),%rsi        # 2005 <_ZStL19piecewise_construct+0x1>
    1448:	48 8d 3d d1 2b 00 00 	lea    0x2bd1(%rip),%rdi        # 4020 <_ZSt4cout@@GLIBCXX_3.4>
    144f:	e8 6c fc ff ff       	callq  10c0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    1454:	c7 85 ac fc ff ff 00 	movl   $0x0,-0x354(%rbp)
    145b:	00 00 00 
    145e:	83 bd ac fc ff ff 1f 	cmpl   $0x1f,-0x354(%rbp)
    1465:	7f 37                	jg     149e <main+0x2b5>
    1467:	8b 85 ac fc ff ff    	mov    -0x354(%rbp),%eax
    146d:	48 98                	cltq   
    146f:	8b 84 85 50 ff ff ff 	mov    -0xb0(%rbp,%rax,4),%eax
    1476:	c5 f9 6e c0          	vmovd  %eax,%xmm0
    147a:	48 8d 3d 9f 2b 00 00 	lea    0x2b9f(%rip),%rdi        # 4020 <_ZSt4cout@@GLIBCXX_3.4>
    1481:	e8 1a fc ff ff       	callq  10a0 <_ZNSolsEf@plt>
    1486:	48 8d 35 81 0b 00 00 	lea    0xb81(%rip),%rsi        # 200e <_ZStL19piecewise_construct+0xa>
    148d:	48 89 c7             	mov    %rax,%rdi
    1490:	e8 2b fc ff ff       	callq  10c0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    1495:	83 85 ac fc ff ff 01 	addl   $0x1,-0x354(%rbp)
    149c:	eb c0                	jmp    145e <main+0x275>
    149e:	48 8b 05 2b 2b 00 00 	mov    0x2b2b(%rip),%rax        # 3fd0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    14a5:	48 89 c6             	mov    %rax,%rsi
    14a8:	48 8d 3d 71 2b 00 00 	lea    0x2b71(%rip),%rdi        # 4020 <_ZSt4cout@@GLIBCXX_3.4>
    14af:	e8 1c fc ff ff       	callq  10d0 <_ZNSolsEPFRSoS_E@plt>
    14b4:	b8 00 00 00 00       	mov    $0x0,%eax
    14b9:	48 8b 75 e8          	mov    -0x18(%rbp),%rsi
    14bd:	64 48 33 34 25 28 00 	xor    %fs:0x28,%rsi
    14c4:	00 00 
    14c6:	74 05                	je     14cd <main+0x2e4>
    14c8:	e8 13 fc ff ff       	callq  10e0 <__stack_chk_fail@plt>
    14cd:	48 81 c4 68 03 00 00 	add    $0x368,%rsp
    14d4:	41 5a                	pop    %r10
    14d6:	5d                   	pop    %rbp
    14d7:	49 8d 62 f8          	lea    -0x8(%r10),%rsp
    14db:	c3                   	retq   

00000000000014dc <_Z41__static_initialization_and_destruction_0ii>:
    14dc:	f3 0f 1e fa          	endbr64 
    14e0:	55                   	push   %rbp
    14e1:	48 89 e5             	mov    %rsp,%rbp
    14e4:	48 83 ec 10          	sub    $0x10,%rsp
    14e8:	89 7d fc             	mov    %edi,-0x4(%rbp)
    14eb:	89 75 f8             	mov    %esi,-0x8(%rbp)
    14ee:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    14f2:	75 32                	jne    1526 <_Z41__static_initialization_and_destruction_0ii+0x4a>
    14f4:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    14fb:	75 29                	jne    1526 <_Z41__static_initialization_and_destruction_0ii+0x4a>
    14fd:	48 8d 3d 2d 2c 00 00 	lea    0x2c2d(%rip),%rdi        # 4131 <_ZStL8__ioinit>
    1504:	e8 e7 fb ff ff       	callq  10f0 <_ZNSt8ios_base4InitC1Ev@plt>
    1509:	48 8d 15 f8 2a 00 00 	lea    0x2af8(%rip),%rdx        # 4008 <__dso_handle>
    1510:	48 8d 35 1a 2c 00 00 	lea    0x2c1a(%rip),%rsi        # 4131 <_ZStL8__ioinit>
    1517:	48 8b 05 da 2a 00 00 	mov    0x2ada(%rip),%rax        # 3ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    151e:	48 89 c7             	mov    %rax,%rdi
    1521:	e8 8a fb ff ff       	callq  10b0 <__cxa_atexit@plt>
    1526:	90                   	nop
    1527:	c9                   	leaveq 
    1528:	c3                   	retq   

0000000000001529 <_GLOBAL__sub_I_main>:
    1529:	f3 0f 1e fa          	endbr64 
    152d:	55                   	push   %rbp
    152e:	48 89 e5             	mov    %rsp,%rbp
    1531:	be ff ff 00 00       	mov    $0xffff,%esi
    1536:	bf 01 00 00 00       	mov    $0x1,%edi
    153b:	e8 9c ff ff ff       	callq  14dc <_Z41__static_initialization_and_destruction_0ii>
    1540:	5d                   	pop    %rbp
    1541:	c3                   	retq   

0000000000001542 <_ZSt3endIfLm32EEPT_RAT0__S0_>:
    1542:	f3 0f 1e fa          	endbr64 
    1546:	55                   	push   %rbp
    1547:	48 89 e5             	mov    %rsp,%rbp
    154a:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    154e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1552:	48 83 e8 80          	sub    $0xffffffffffffff80,%rax
    1556:	5d                   	pop    %rbp
    1557:	c3                   	retq   

0000000000001558 <_ZSt4fillIPfiEvT_S1_RKT0_>:
    1558:	f3 0f 1e fa          	endbr64 
    155c:	55                   	push   %rbp
    155d:	48 89 e5             	mov    %rsp,%rbp
    1560:	53                   	push   %rbx
    1561:	48 83 ec 28          	sub    $0x28,%rsp
    1565:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1569:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    156d:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    1571:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1575:	48 89 c7             	mov    %rax,%rdi
    1578:	e8 2c 00 00 00       	callq  15a9 <_ZSt12__niter_baseIPfET_S1_>
    157d:	48 89 c3             	mov    %rax,%rbx
    1580:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1584:	48 89 c7             	mov    %rax,%rdi
    1587:	e8 1d 00 00 00       	callq  15a9 <_ZSt12__niter_baseIPfET_S1_>
    158c:	48 89 c1             	mov    %rax,%rcx
    158f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1593:	48 89 c2             	mov    %rax,%rdx
    1596:	48 89 de             	mov    %rbx,%rsi
    1599:	48 89 cf             	mov    %rcx,%rdi
    159c:	e8 1a 00 00 00       	callq  15bb <_ZSt8__fill_aIPfiEN9__gnu_cxx11__enable_ifIXsrSt11__is_scalarIT0_E7__valueEvE6__typeET_S8_RKS4_>
    15a1:	90                   	nop
    15a2:	48 83 c4 28          	add    $0x28,%rsp
    15a6:	5b                   	pop    %rbx
    15a7:	5d                   	pop    %rbp
    15a8:	c3                   	retq   

00000000000015a9 <_ZSt12__niter_baseIPfET_S1_>:
    15a9:	f3 0f 1e fa          	endbr64 
    15ad:	55                   	push   %rbp
    15ae:	48 89 e5             	mov    %rsp,%rbp
    15b1:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    15b5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    15b9:	5d                   	pop    %rbp
    15ba:	c3                   	retq   

00000000000015bb <_ZSt8__fill_aIPfiEN9__gnu_cxx11__enable_ifIXsrSt11__is_scalarIT0_E7__valueEvE6__typeET_S8_RKS4_>:
    15bb:	f3 0f 1e fa          	endbr64 
    15bf:	55                   	push   %rbp
    15c0:	48 89 e5             	mov    %rsp,%rbp
    15c3:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    15c7:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    15cb:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    15cf:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    15d3:	8b 00                	mov    (%rax),%eax
    15d5:	89 45 fc             	mov    %eax,-0x4(%rbp)
    15d8:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    15dc:	48 3b 45 e0          	cmp    -0x20(%rbp),%rax
    15e0:	74 14                	je     15f6 <_ZSt8__fill_aIPfiEN9__gnu_cxx11__enable_ifIXsrSt11__is_scalarIT0_E7__valueEvE6__typeET_S8_RKS4_+0x3b>
    15e2:	c5 fa 2a 45 fc       	vcvtsi2ssl -0x4(%rbp),%xmm0,%xmm0
    15e7:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    15eb:	c5 fa 11 00          	vmovss %xmm0,(%rax)
    15ef:	48 83 45 e8 04       	addq   $0x4,-0x18(%rbp)
    15f4:	eb e2                	jmp    15d8 <_ZSt8__fill_aIPfiEN9__gnu_cxx11__enable_ifIXsrSt11__is_scalarIT0_E7__valueEvE6__typeET_S8_RKS4_+0x1d>
    15f6:	90                   	nop
    15f7:	5d                   	pop    %rbp
    15f8:	c3                   	retq   
    15f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001600 <__libc_csu_init>:
    1600:	f3 0f 1e fa          	endbr64 
    1604:	41 57                	push   %r15
    1606:	4c 8d 3d 5b 27 00 00 	lea    0x275b(%rip),%r15        # 3d68 <__frame_dummy_init_array_entry>
    160d:	41 56                	push   %r14
    160f:	49 89 d6             	mov    %rdx,%r14
    1612:	41 55                	push   %r13
    1614:	49 89 f5             	mov    %rsi,%r13
    1617:	41 54                	push   %r12
    1619:	41 89 fc             	mov    %edi,%r12d
    161c:	55                   	push   %rbp
    161d:	48 8d 2d 54 27 00 00 	lea    0x2754(%rip),%rbp        # 3d78 <__init_array_end>
    1624:	53                   	push   %rbx
    1625:	4c 29 fd             	sub    %r15,%rbp
    1628:	48 83 ec 08          	sub    $0x8,%rsp
    162c:	e8 cf f9 ff ff       	callq  1000 <_init>
    1631:	48 c1 fd 03          	sar    $0x3,%rbp
    1635:	74 1f                	je     1656 <__libc_csu_init+0x56>
    1637:	31 db                	xor    %ebx,%ebx
    1639:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1640:	4c 89 f2             	mov    %r14,%rdx
    1643:	4c 89 ee             	mov    %r13,%rsi
    1646:	44 89 e7             	mov    %r12d,%edi
    1649:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    164d:	48 83 c3 01          	add    $0x1,%rbx
    1651:	48 39 dd             	cmp    %rbx,%rbp
    1654:	75 ea                	jne    1640 <__libc_csu_init+0x40>
    1656:	48 83 c4 08          	add    $0x8,%rsp
    165a:	5b                   	pop    %rbx
    165b:	5d                   	pop    %rbp
    165c:	41 5c                	pop    %r12
    165e:	41 5d                	pop    %r13
    1660:	41 5e                	pop    %r14
    1662:	41 5f                	pop    %r15
    1664:	c3                   	retq   
    1665:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    166c:	00 00 00 00 

0000000000001670 <__libc_csu_fini>:
    1670:	f3 0f 1e fa          	endbr64 
    1674:	c3                   	retq   

Disassembly of section .fini:

0000000000001678 <_fini>:
    1678:	f3 0f 1e fa          	endbr64 
    167c:	48 83 ec 08          	sub    $0x8,%rsp
    1680:	48 83 c4 08          	add    $0x8,%rsp
    1684:	c3                   	retq   
