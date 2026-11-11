[2K            ; CALL XREF from sym.func.1000041cc @ 0x1000042f4
            ; CALL XREF from entry0 @ 0x10000616c
/ sym.func.100001544();
|           ; var int64_t var_80h @ stack - 0x80
|           ; var int64_t var_70h @ stack - 0x70
|           ; var int64_t var_68h @ stack - 0x68
|           ; var int64_t var_64h @ stack - 0x64
|           ; var int64_t var_60h @ stack - 0x60
|           ; var int64_t var_50h @ stack - 0x50
|           ; var int64_t var_40h @ stack - 0x40
|           ; var int64_t var_30h @ stack - 0x30
|           ; var int64_t var_20h @ stack - 0x20
|           ; var int64_t var_10h @ stack - 0x10
|           0x100001544      pacibsp
|           0x100001548      sub   sp, sp, 0x80
|           0x10000154c      stp   x28, x27, [var_60h]
|           0x100001550      stp   x26, x25, [var_50h]
|           0x100001554      stp   x24, x23, [var_40h]
|           0x100001558      stp   x22, x21, [var_30h]
|           0x10000155c      stp   x20, x19, [var_20h]
|           0x100001560      stp   x29, x30, [var_10h]
|           0x100001564      add   x29, sp, 0x70
|           0x100001568      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|           0x10000156c      ldr   x0, [x8, 0xc28]                     ; [0x10000cc28:4]=0x1c190 ; reloc.NSMutableArray
|           0x100001570      bl    stub.objc_msgSend_array             ;  stub.objc_msgSend_array(void)
|           0x100001574      bl    sym.imp.objc_claimAutoreleasedReturnValue
|           0x100001578      mov   x19, x0
|           0x10000157c      adrp  x0, data.100007000                  ; 0x100007000
|           0x100001580      add   x0, x0, 0xcc6                       ; 0x100007cc6 ; "AppleHPMDevice"
|           0x100001584      bl    sym.imp.IOServiceMatching
|           0x100001588      str   wzr, [var_64h]
|       ,=< 0x10000158c      cbz   x0, 0x100001a7c
|       |   0x100001590      mov   x1, x0
|       |   0x100001594      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|       |   0x100001598      ldr   x8, [x8, 0xc40]                     ; [0x10000cc40:4]=0x1c1a8 ; reloc.kIOMasterPortDefault
|       |   0x10000159c      ldr   w0, [x8]                            ; [0x10001c1a8:4]=0
|       |                                                              ; str.const
|       |   0x1000015a0      add   x2, var_64h
|       |   0x1000015a4      bl    sym.imp.IOServiceGetMatchingServices
|       |   0x1000015a8      mov   x8, x0
|       |   0x1000015ac      ldr   w0, [var_64h]                       ; [0x1c:4]=-1 ; 28
|      ,==< 0x1000015b0      cbz   w0, 0x100001a7c
|     ,===< 0x1000015b4      cbnz  w8, 0x100001a70
|     |||   0x1000015b8      bl    sym.imp.IOIteratorReset
|     |||   0x1000015bc      ldr   w0, [var_64h]                       ; [0x1c:4]=-1 ; 28
|     |||   0x1000015c0      bl    sym.imp.IOIteratorNext
|    ,====< 0x1000015c4      cbz   w0, 0x100001a70
|    ||||   0x1000015c8      mov   x25, x0
|    ||||   0x1000015cc      mov   w26, 0
|    ||||   0x1000015d0      mov   w21, 0x2f0
|    ||||   0x1000015d4      movk  w21, 0xe000, lsl 16
|    ||||   0x1000015d8      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|    ||||   0x1000015dc      ldr   x8, [x8, 0xc38]                     ; [0x10000cc38:4]=0x1c1a0 ; reloc.kCFAllocatorDefault
|    ||||   0x1000015e0      adrp  x20, section.7.__DATA_CONST.__const ; 0x10000c000
|    ||||   0x1000015e4      add   x20, x20, 0x3c0                     ; 0x10000c3c0
|    ||||                                                              ; reloc.__CFConstantStringClassReference.10000c3c0
|    ||||   0x1000015e8      ldr   x8, [x8]                            ; [0x10001c1a0:4]=0
|    ||||                                                              ; reloc.target.kCFAllocatorDefault
|    ||||   0x1000015ec      str   x8, [var_70h]
|    ||||   0x1000015f0      adrp  x8, data.100007000                  ; 0x100007000
|    ||||   0x1000015f4      ldr   q0, [x8, 0xac0]                     ; [0x100007ac0:4]=0
|    ||||                                                              ; section.3.__TEXT.__const
|    ||||   0x1000015f8      str   q0, [sp]
|    ||||   0x1000015fc      adrp  x22, data.100007000                 ; 0x100007000
|    ||||   0x100001600      add   x22, x22, 0xd58                     ; 0x100007d58 ; "IOService"
|    ||||   0x100001604      adrp  x23, data.100007000                 ; 0x100007000
|    ||||   0x100001608      add   x23, x23, 0xc9f                     ; 0x100007c9f ; "IOThunderboltSwitch"
|   .-----> 0x10000160c      str   wzr, [var_68h]
|   :||||   0x100001610      add   x2, var_68h
|   :||||   0x100001614      mov   x0, x25                             ; int64_t arg3
|   :||||   0x100001618      mov   x1, x20
|   :||||   0x10000161c      bl    sym.func.100000d7c
|   :||||   0x100001620      ldr   w8, [var_68h]                       ; [0x18:4]=-1 ; 24
|   :||||   0x100001624      orr   w8, w0, w8
|   :||||   0x100001628      cmp   w8, 0
|   :||||   0x10000162c      cset  w8, eq
|   :||||   0x100001630      cmp   w0, w21
|   :||||   0x100001634      ccmp  w8, 0, 0, ne
|  ,======< 0x100001638      b.eq  0x100001a60
|  |:||||   0x10000163c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x100001640      ldr   x0, [x8, 0xc30]                     ; [0x10000cc30:4]=0x1c198 ; reloc.NSMutableDictionary
|  |:||||   0x100001644      bl    stub.objc_msgSend_dictionary        ;  stub.objc_msgSend_dictionary(void)
|  |:||||   0x100001648      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  |:||||   0x10000164c      mov   x27, x0
|  |:||||   0x100001650      str   wzr, [var_68h]
|  |:||||   0x100001654      add   x2, var_68h
|  |:||||   0x100001658      mov   x0, x25                             ; int64_t arg3
|  |:||||   0x10000165c      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x100001660      add   x1, x1, 0x180                       ; 0x10000c180
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c180
|  |:||||   0x100001664      bl    sym.func.100000d7c
| ,=======< 0x100001668      cbnz  w0, 0x1000016a0
| ||:||||   0x10000166c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x100001670      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ||:||||   0x100001674      ldr   w2, [var_68h]                       ; [0x18:4]=-1 ; 24
| ||:||||   0x100001678      bl    stub.objc_msgSend_numberWithInt:    ;  stub.objc_msgSend_numberWithInt:(void)
| ||:||||   0x10000167c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||:||||   0x100001680      mov   x24, x0
| ||:||||   0x100001684      mov   x0, x27
| ||:||||   0x100001688      mov   x2, x24
| ||:||||   0x10000168c      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x100001690      add   x3, x3, 0x180                       ; 0x10000c180
| ||:||||                                                              ; reloc.__CFConstantStringClassReference.10000c180
| ||:||||   0x100001694      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| ||:||||   0x100001698      mov   x0, x24                             ; void *instance
| ||:||||   0x10000169c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| `-------> 0x1000016a0      str   wzr, [var_68h]
|  |:||||   0x1000016a4      add   x2, var_68h
|  |:||||   0x1000016a8      mov   x0, x25                             ; int64_t arg3
|  |:||||   0x1000016ac      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x1000016b0      add   x1, x1, 0x1c0                       ; 0x10000c1c0
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c1c0
|  |:||||   0x1000016b4      bl    sym.func.100000d7c
| ,=======< 0x1000016b8      cbnz  w0, 0x1000016f0
| ||:||||   0x1000016bc      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x1000016c0      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ||:||||   0x1000016c4      ldr   w2, [var_68h]                       ; [0x18:4]=-1 ; 24
| ||:||||   0x1000016c8      bl    stub.objc_msgSend_numberWithInt:    ;  stub.objc_msgSend_numberWithInt:(void)
| ||:||||   0x1000016cc      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||:||||   0x1000016d0      mov   x24, x0
| ||:||||   0x1000016d4      mov   x0, x27
| ||:||||   0x1000016d8      mov   x2, x24
| ||:||||   0x1000016dc      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x1000016e0      add   x3, x3, 0x3e0                       ; 0x10000c3e0
| ||:||||                                                              ; reloc.__CFConstantStringClassReference.10000c3e0
| ||:||||   0x1000016e4      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| ||:||||   0x1000016e8      mov   x0, x24                             ; void *instance
| ||:||||   0x1000016ec      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| `-------> 0x1000016f0      str   wzr, [var_68h]
|  |:||||   0x1000016f4      add   x2, var_68h
|  |:||||   0x1000016f8      mov   x0, x25                             ; int64_t arg3
|  |:||||   0x1000016fc      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x100001700      add   x1, x1, 0x200                       ; 0x10000c200
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c200
|  |:||||   0x100001704      bl    sym.func.100000d7c
| ,=======< 0x100001708      cbnz  w0, 0x100001740
| ||:||||   0x10000170c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x100001710      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ||:||||   0x100001714      ldr   w2, [var_68h]                       ; [0x18:4]=-1 ; 24
| ||:||||   0x100001718      bl    stub.objc_msgSend_numberWithInt:    ;  stub.objc_msgSend_numberWithInt:(void)
| ||:||||   0x10000171c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||:||||   0x100001720      mov   x24, x0
| ||:||||   0x100001724      mov   x0, x27
| ||:||||   0x100001728      mov   x2, x24
| ||:||||   0x10000172c      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x100001730      add   x3, x3, 0x400                       ; 0x10000c400
| ||:||||                                                              ; reloc.__CFConstantStringClassReference.10000c400
| ||:||||   0x100001734      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| ||:||||   0x100001738      mov   x0, x24                             ; void *instance
| ||:||||   0x10000173c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| `-------> 0x100001740      str   wzr, [var_68h]
|  |:||||   0x100001744      add   x2, var_68h
|  |:||||   0x100001748      mov   x0, x25                             ; int64_t arg3
|  |:||||   0x10000174c      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x100001750      add   x1, x1, 0x240                       ; 0x10000c240
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c240
|  |:||||   0x100001754      bl    sym.func.100000d7c
| ,=======< 0x100001758      cbnz  w0, 0x100001790
| ||:||||   0x10000175c      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x100001760      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ||:||||   0x100001764      ldr   w2, [var_68h]                       ; [0x18:4]=-1 ; 24
| ||:||||   0x100001768      bl    stub.objc_msgSend_numberWithInt:    ;  stub.objc_msgSend_numberWithInt:(void)
| ||:||||   0x10000176c      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||:||||   0x100001770      mov   x24, x0
| ||:||||   0x100001774      mov   x0, x27
| ||:||||   0x100001778      mov   x2, x24
| ||:||||   0x10000177c      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x100001780      add   x3, x3, 0x420                       ; 0x10000c420
| ||:||||                                                              ; reloc.__CFConstantStringClassReference.10000c420
| ||:||||   0x100001784      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| ||:||||   0x100001788      mov   x0, x24                             ; void *instance
| ||:||||   0x10000178c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| `-------> 0x100001790      str   wzr, [var_68h]
|  |:||||   0x100001794      add   x2, var_68h
|  |:||||   0x100001798      mov   x0, x25                             ; int64_t arg3
|  |:||||   0x10000179c      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x1000017a0      add   x1, x1, 0x440                       ; 0x10000c440
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c440
|  |:||||   0x1000017a4      bl    sym.func.100000d7c
| ,=======< 0x1000017a8      cbnz  w0, 0x1000017e0
| ||:||||   0x1000017ac      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x1000017b0      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ||:||||   0x1000017b4      ldr   w2, [var_68h]                       ; [0x18:4]=-1 ; 24
| ||:||||   0x1000017b8      bl    stub.objc_msgSend_numberWithInt:    ;  stub.objc_msgSend_numberWithInt:(void)
| ||:||||   0x1000017bc      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||:||||   0x1000017c0      mov   x24, x0
| ||:||||   0x1000017c4      mov   x0, x27
| ||:||||   0x1000017c8      mov   x2, x24
| ||:||||   0x1000017cc      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x1000017d0      add   x3, x3, 0x460                       ; 0x10000c460
| ||:||||                                                              ; reloc.__CFConstantStringClassReference.10000c460
| ||:||||   0x1000017d4      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| ||:||||   0x1000017d8      mov   x0, x24                             ; void *instance
| ||:||||   0x1000017dc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| `-------> 0x1000017e0      str   wzr, [var_68h]
|  |:||||   0x1000017e4      add   x2, var_68h
|  |:||||   0x1000017e8      mov   x0, x25                             ; int64_t arg3
|  |:||||   0x1000017ec      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x1000017f0      add   x1, x1, 0x480                       ; 0x10000c480
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c480
|  |:||||   0x1000017f4      bl    sym.func.100000d7c
| ,=======< 0x1000017f8      cbz   w0, 0x100001804
| ||:||||   0x1000017fc      mov   w28, 1
| ========< 0x100001800      b     0x10000184c
| `-------> 0x100001804      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x100001808      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
|  |:||||   0x10000180c      ldr   w24, [var_68h]                      ; [0x18:4]=-1 ; 24
|  |:||||   0x100001810      mov   x2, x24
|  |:||||   0x100001814      bl    stub.objc_msgSend_numberWithInt:    ;  stub.objc_msgSend_numberWithInt:(void)
|  |:||||   0x100001818      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  |:||||   0x10000181c      mov   x21, x0
|  |:||||   0x100001820      mov   x0, x27
|  |:||||   0x100001824      mov   x2, x21
|  |:||||   0x100001828      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x10000182c      add   x3, x3, 0x4a0                       ; 0x10000c4a0
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c4a0
|  |:||||   0x100001830      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
|  |:||||   0x100001834      mov   x0, x21                             ; void *instance
|  |:||||   0x100001838      mov   w21, 0x2f0
|  |:||||   0x10000183c      movk  w21, 0xe000, lsl 16
|  |:||||   0x100001840      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |:||||   0x100001844      cmp   w24, 0
|  |:||||   0x100001848      cset  w28, eq
|  |:||||   ; CODE XREF from sym.func.100001544 @ 0x100001800
| --------> 0x10000184c      str   wzr, [var_68h]
|  |:||||   0x100001850      add   x2, var_68h
|  |:||||   0x100001854      mov   x0, x25                             ; int64_t arg3
|  |:||||   0x100001858      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x10000185c      add   x1, x1, 0x360                       ; 0x10000c360
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c360
|  |:||||   0x100001860      bl    sym.func.100000d7c
| ,=======< 0x100001864      cbnz  w0, 0x10000193c
| ||:||||   0x100001868      ldr   w8, [var_68h]                       ; [0x18:4]=-1 ; 24
| ========< 0x10000186c      cbz   w8, 0x100001900
| ||:||||   0x100001870      mov   w9, 0
| ||:||||   0x100001874      mov   w2, 0
| ||:||||   0x100001878      movi  v4.4s, 0xa
| ||:||||   0x10000187c      ldr   q5, [sp]
| --------> 0x100001880      and   w10, w8, 0xf
| ||:||||   0x100001884      ands  w9, w9, 0xff
| ========< 0x100001888      b.eq  0x1000018e8
| ||:||||   0x10000188c      add   w11, w9, 3
| ||:||||   0x100001890      and   w11, w11, 0x1fc
| ||:||||   0x100001894      sub   w12, w9, 1
| ||:||||   0x100001898      movi  v0.4s, 1
| ||:||||   0x10000189c      mov   v0.s[0], w10
| ||:||||   0x1000018a0      dup   v1.4s, w12
| ||:||||   0x1000018a4      mov   w10, 4
| --------> 0x1000018a8      mov   v2.16b, v0.16b
| ||:||||   0x1000018ac      mul   v0.4s, v0.4s, v4.4s
| ||:||||   0x1000018b0      sub   w10, w10, 4
| ||:||||   0x1000018b4      add   w12, w11, w10
| ||:||||   0x1000018b8      cmp   w12, 4
| ========< 0x1000018bc      b.ne  0x1000018a8
| ||:||||   0x1000018c0      neg   w10, w10
| ||:||||   0x1000018c4      dup   v3.4s, w10
| ||:||||   0x1000018c8      orr   v3.16b, v3.16b, v5.16b
| ||:||||   0x1000018cc      cmhi  v1.4s, v3.4s, v1.4s
| ||:||||   0x1000018d0      bit   v0.16b, v2.16b, v1.16b
| ||:||||   0x1000018d4      ext   v1.16b, v0.16b, v0.16b, 8
| ||:||||   0x1000018d8      mul   v0.2s, v0.2s, v1.2s
| ||:||||   0x1000018dc      mov   w10, v0.s[1]
| ||:||||   0x1000018e0      fmov  w11, s0
| ||:||||   0x1000018e4      mul   w10, w11, w10
| --------> 0x1000018e8      add   w9, w9, 1
| ||:||||   0x1000018ec      add   w2, w10, w2
| ||:||||   0x1000018f0      cmp   w8, 0xf
| ||:||||   0x1000018f4      lsr   w8, w8, 4
| ========< 0x1000018f8      b.hi  0x100001880
| ========< 0x1000018fc      b     0x100001904
| --------> 0x100001900      mov   w2, 0
| ||:||||   ; CODE XREF from sym.func.100001544 @ 0x1000018fc
| --------> 0x100001904      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x100001908      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
| ||:||||   0x10000190c      bl    stub.objc_msgSend_numberWithInt:    ;  stub.objc_msgSend_numberWithInt:(void)
| ||:||||   0x100001910      bl    sym.imp.objc_claimAutoreleasedReturnValue
| ||:||||   0x100001914      mov   x21, x0
| ||:||||   0x100001918      mov   x0, x27
| ||:||||   0x10000191c      mov   x2, x21
| ||:||||   0x100001920      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x100001924      add   x3, x3, 0x360                       ; 0x10000c360
| ||:||||                                                              ; reloc.__CFConstantStringClassReference.10000c360
| ||:||||   0x100001928      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| ||:||||   0x10000192c      mov   x0, x21                             ; void *instance
| ||:||||   0x100001930      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ||:||||   0x100001934      mov   w21, 0x2f0
| ||:||||   0x100001938      movk  w21, 0xe000, lsl 16
| `-------> 0x10000193c      str   wzr, [var_68h]
|  |:||||   0x100001940      add   x2, var_68h
|  |:||||   0x100001944      mov   x0, x25                             ; int64_t arg3
|  |:||||   0x100001948      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x10000194c      add   x1, x1, 0x480                       ; 0x10000c480
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c480
|  |:||||   0x100001950      bl    sym.func.100000d7c
| ,=======< 0x100001954      cbz   w0, 0x100001964
| ========< 0x100001958      cbz   w26, 0x1000019a4
| --------> 0x10000195c      mov   x24, 0
| ========< 0x100001960      b     0x1000019c0
| `-------> 0x100001964      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x100001968      ldr   x0, [x8, 0xbd8]                     ; [0x10000cbd8:4]=0x1c140 ; "@\xc1\U00000001"
|  |:||||   0x10000196c      ldr   w2, [var_68h]                       ; [0x18:4]=-1 ; 24
|  |:||||   0x100001970      bl    stub.objc_msgSend_numberWithInt:    ;  stub.objc_msgSend_numberWithInt:(void)
|  |:||||   0x100001974      bl    sym.imp.objc_claimAutoreleasedReturnValue
|  |:||||   0x100001978      mov   x21, x0
|  |:||||   0x10000197c      mov   x0, x27
|  |:||||   0x100001980      mov   x2, x21
|  |:||||   0x100001984      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x100001988      add   x3, x3, 0x4a0                       ; 0x10000c4a0
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c4a0
|  |:||||   0x10000198c      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
|  |:||||   0x100001990      mov   x0, x21                             ; void *instance
|  |:||||   0x100001994      mov   w21, 0x2f0
|  |:||||   0x100001998      movk  w21, 0xe000, lsl 16
|  |:||||   0x10000199c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
| ========< 0x1000019a0      cbnz  w26, 0x10000195c
| --------> 0x1000019a4      mov   x0, x25
|  |:||||   0x1000019a8      adrp  x1, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x1000019ac      add   x1, x1, 0x4c0                       ; 0x10000c4c0
|  |:||||                                                              ; reloc.__CFConstantStringClassReference.10000c4c0
|  |:||||   0x1000019b0      ldr   x2, [var_70h]                       ; [0x10:4]=-1 ; 16
|  |:||||   0x1000019b4      mov   w3, 0
|  |:||||   0x1000019b8      bl    sym.imp.IORegistryEntryCreateCFProperty
|  |:||||   0x1000019bc      mov   x24, x0
|  |:||||   ; CODE XREF from sym.func.100001544 @ 0x100001960
| --------> 0x1000019c0      adrp  x8, section.7.__DATA_CONST.__const  ; 0x10000c000
|  |:||||   0x1000019c4      ldr   x0, [x8, 0xbe8]                     ; [0x10000cbe8:4]=0x1c150 ; "P\xc1\U00000001"
|  |:||||   0x1000019c8      bl    sym.imp.objc_opt_class
|  |:||||   0x1000019cc      mov   x1, x0
|  |:||||   0x1000019d0      mov   x0, x24
|  |:||||   0x1000019d4      bl    sym.imp.objc_opt_isKindOfClass
|  |:||||   0x1000019d8      tst   w0, 1
|  |:||||   0x1000019dc      csel  w26, w26, w21, ne
| ,=======< 0x1000019e0      cbnz  w26, 0x1000019f8
| ||:||||   0x1000019e4      mov   x0, x27
| ||:||||   0x1000019e8      mov   x2, x24
| ||:||||   0x1000019ec      adrp  x3, section.7.__DATA_CONST.__const  ; 0x10000c000
| ||:||||   0x1000019f0      add   x3, x3, 0x4e0                       ; 0x10000c4e0
| ||:||||                                                              ; reloc.__CFConstantStringClassReference.10000c4e0
| ||:||||   0x1000019f4      bl    stub.objc_msgSend_setObject:forKey: ;  stub.objc_msgSend_setObject:forKey:(void)
| `-------> 0x1000019f8      mov   x0, x24                             ; void *instance
|  |:||||   0x1000019fc      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  |:||||   0x100001a00      str   wzr, [var_68h]
|  |:||||   0x100001a04      add   x2, var_68h
|  |:||||   0x100001a08      mov   x0, x25
|  |:||||   ; CODE XREF from sym.func.100001544 @ 0x100001a38
| .-------> 0x100001a0c      mov   x1, x22
| :|:||||   0x100001a10      bl    sym.imp.IORegistryEntryGetParentEntry
| ========< 0x100001a14      cbnz  w0, 0x100001a4c
| :|:||||   0x100001a18      ldr   w24, [var_68h]                      ; [0x18:4]=-1 ; 24
| :|:||||   0x100001a1c      mov   x0, x24
| :|:||||   0x100001a20      mov   x1, x23
| :|:||||   0x100001a24      bl    sym.imp.IOObjectConformsTo
| ========< 0x100001a28      cbnz  w0, 0x100001a3c
| :|:||||   0x100001a2c      str   wzr, [var_68h]
| :|:||||   0x100001a30      add   x2, var_68h
| :|:||||   0x100001a34      mov   x0, x24
| `=======< 0x100001a38      b     0x100001a0c
| --------> 0x100001a3c      mov   x0, x24                             ; int64_t arg1
|  |:||||   0x100001a40      mov   x1, x27                             ; int64_t arg2
|  |:||||   0x100001a44      bl    sym.func.100000f20
| ,=======< 0x100001a48      tbz   w28, 0, 0x100001a58
| --------> 0x100001a4c      mov   x0, x19
| ||:||||   0x100001a50      mov   x2, x27
| ||:||||   0x100001a54      bl    stub.objc_msgSend_addObject:        ;  stub.objc_msgSend_addObject:(void)
| `-------> 0x100001a58      mov   x0, x27                             ; void *instance
|  |:||||   0x100001a5c      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|  `------> 0x100001a60      ldr   w0, [var_64h]                       ; [0x1c:4]=-1 ; 28
|   :||||   0x100001a64      bl    sym.imp.IOIteratorNext
|   :||||   0x100001a68      mov   x25, x0
|   `=====< 0x100001a6c      cbnz  w0, 0x10000160c
|    ``---> 0x100001a70      ldr   w0, [var_64h]                       ; [0x1c:4]=-1 ; 28
|     ,===< 0x100001a74      cbz   w0, 0x100001a7c
|     |||   0x100001a78      bl    sym.imp.IOObjectRelease
|     ```-> 0x100001a7c      mov   x0, x19
|           0x100001a80      bl    stub.objc_msgSend_count             ;  stub.objc_msgSend_count(void)
|       ,=< 0x100001a84      cbz   x0, 0x100001a98
|       |   0x100001a88      mov   x0, x19                             ; void *instance
|       |   0x100001a8c      bl    sym.imp.objc_retain                 ; void objc_retain(void *instance)
|       |   0x100001a90      mov   x20, x0
|      ,==< 0x100001a94      b     0x100001a9c
|      |`-> 0x100001a98      mov   x20, 0
|      |    ; CODE XREF from sym.func.100001544 @ 0x100001a94
|      `--> 0x100001a9c      mov   x0, x19                             ; void *instance
|           0x100001aa0      bl    sym.imp.objc_release                ; void objc_release(void *instance)
|           0x100001aa4      mov   x0, x20
|           0x100001aa8      ldp   x29, x30, [var_10h]
|           0x100001aac      ldp   x20, x19, [var_20h]
|           0x100001ab0      ldp   x22, x21, [var_30h]
|           0x100001ab4      ldp   x24, x23, [var_40h]
|           0x100001ab8      ldp   x26, x25, [var_50h]
|           0x100001abc      ldp   x28, x27, [var_60h]
|           0x100001ac0      add   sp, sp, 0x80
|           0x100001ac4      autibsp
|           0x100001ac8      eor   x16, x30, x30, lsl 1
|       ,=< 0x100001acc      tbz   x16, 0x3e, 0x100001ad4
|       |   0x100001ad0      brk   0xc471
\      ,`-> 0x100001ad4      b     sym.imp.objc_autoreleaseReturnValue
