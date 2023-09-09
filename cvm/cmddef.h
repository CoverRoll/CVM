#ifdef __cplusplus
extern "C++" {
#endif

#ifndef _CVM_CMDDEF_H
#define _CVM_CMDDEF_H

typedef enum command_index{
    null = 0x0,
    // mov指令
    mov_i8tr = 0x1,  // 存数据到默认寄存器
    mov_i64tr,
    mov_fm,  // 从内存地址读取数据到默认寄存器
    mov_tm,  // 从默认寄存器读取数据(低8位)，写入到内存地址
    mov_r8tr,  // 从寄存器地址读取数据，写入到内存地址
    mov_r64tr,

    // 保护模式指令 与 系统调用指令
    set_prot = 0x10,  // 设置保护模式索引表
    jmp_prot,  // 跳转并开始保护
    stop_prot,  // 终止保护模式
    stop,  // 中断程序 按照中断信息码查询程序使用内核镜像映射的中断处理程序地址
    call,  // 跳转到内核区域的虚拟地址, 控制权交给内核空间, 并暂时转到内核模式

    // 跳转指令
    jmp_ti_if = 0x20,
    jmp_ti_ifn,
    jmp_tr_if,
    jmp_tr_ifn,
    jmp_tm_if,
    jmp_tm_ifn,

    // 基本数学运算
    l_sal8 = 0x30,  // 左移运算
    l_sal64,
    l_sar8,  // 右移运算
    l_sar64,

    l_and,
    l_or,
    l_xor,
    l_not,  // 0x37

    c_eq8,
    c_eq64,
    c_high8,
    c_high64,
    c_low8,
    c_low64,

    b_add8,  // 0x3e
    b_add64,
    b_sub8,
    b_sub64,
    b_mcl8,
    b_mcl64,
    b_div8,
    b_div64,  // 0x45
} cmd_index;

#endif

#ifdef __cplusplus
}
#endif
