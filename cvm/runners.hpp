#include <cstdio>
#include "vmclass.hpp"
#include "vm_template.hpp"
#include "cmddef.h"
#include "datatypedef.h"
#include "resdef.h"

#ifndef _CVM_RUNNERS_HPP
#define _CVM_RUNNERS_HPP

vm_template
bool VM<res_size>::run_command(command cmd){
    cmd_index tmp;
    tmp = (cmd_index)cmd.cmd;
    switch (tmp){
    case mov_i8tr:  // 将指令数据中的数据写到寄存器
        set_res_chr(RES_DE, cmd.data.data8);
        break;
    case mov_i64tr:
        set_res(RES_DE, cmd.data.data64);
        break;
    case mov_fm:  // 将内存数据写到寄存器
        set_res_chr(RES_DE, get_mem(cmd.data.mem));
        break;
    case mov_tm:  // 将默认寄存器的数据写到内存
        set_mem(cmd.data.mem, get_res_chr(RES_DE));
        break;
    case mov_r8tr:
        set_res_chr(cmd.data.res.b, get_res_chr(cmd.data.res.a));
        break;
    case mov_r64tr:
        set_res(cmd.data.res.b, get_res(cmd.data.res.a));
        break;
    case mov_rmtr:
        set_res_chr(cmd.data.res.b, get_mem(get_res(cmd.data.res.a)));
        break;
    case mov_rtrm:
        set_mem(get_res(cmd.data.res.b), get_res_chr(cmd.data.res.a));
        break;




    case stop:
        return(true);
        break;



    case jmp_ti_if:
        if(get_res(RES_DE)){
            set_res(RES_LN, cmd.data.data64);
        }
        return(false);
        break;
    case jmp_ti_ifn:
        if(!(get_res(RES_DE))){
            set_res(RES_LN, cmd.data.data64);
        }
        return(false);
        break;
    case jmp_tr_if:
        if(get_res(cmd.data.res.a)){
            set_res(RES_LN, cmd.data.res.b);
        }
        return(false);
        break;
    case jmp_tr_ifn:
        if(!(get_res(cmd.data.res.a))){
            set_res(RES_LN, cmd.data.res.b);
        }
        return(false);
        break;
    case jmp_tm_if:
        if(get_res(RES_DE)){
            set_res(RES_LN, get_mem(cmd.data.mem));
        }
        return(false);
        break;
    case jmp_tm_ifn:
        if(!(get_res(RES_DE))){
            set_res(RES_LN, get_mem(cmd.data.mem));
        }
        return(false);
        break;



    case l_sal8:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)<<get_res_chr(cmd.data.res.b));
        break;
    case l_sal64:
        set_res(cmd.data.res.c, get_res(cmd.data.res.a)<<get_res_chr(cmd.data.res.b));
        break;
    case l_sar8:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)>>get_res_chr(cmd.data.res.b));
        break;
    case l_sar64:
        set_res(cmd.data.res.c, get_res(cmd.data.res.a)>>get_res_chr(cmd.data.res.b));
        break;
    case l_and:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)&get_res_chr(cmd.data.res.b));
        break;
    case l_or:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)|get_res_chr(cmd.data.res.b));
        break;
    case l_xor:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)^get_res_chr(cmd.data.res.b));
        break;
    case l_not:
        set_res_chr(cmd.data.res.b, ~(get_res_chr(cmd.data.res.a)));
        break;
    case c_eq8:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)==get_res_chr(cmd.data.res.b));
        break;
    case c_eq64:
        set_res_chr(cmd.data.res.c, get_res(cmd.data.res.a)==get_res(cmd.data.res.b));
        break;
    case c_high8:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)>get_res_chr(cmd.data.res.b));
        break;
    case c_high64:
        set_res_chr(cmd.data.res.c, get_res(cmd.data.res.a)>get_res(cmd.data.res.b));
        break;
    case c_low8:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)<get_res_chr(cmd.data.res.b));
        break;
    case c_low64:
        set_res_chr(cmd.data.res.c, get_res(cmd.data.res.a)<get_res(cmd.data.res.b));
        break;



    case b_add8:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)+get_res_chr(cmd.data.res.b));
        break;
    case b_add64:
        set_res(cmd.data.res.c, get_res(cmd.data.res.a)+get_res(cmd.data.res.b));
        break;
    case b_sub8:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)-get_res_chr(cmd.data.res.b));
        break;
    case b_sub64:
        set_res(cmd.data.res.c, get_res(cmd.data.res.a)-get_res(cmd.data.res.b));
        break;
    case b_mcl8:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)*get_res_chr(cmd.data.res.b));
        break;
    case b_mcl64:
        set_res(cmd.data.res.c, get_res(cmd.data.res.a)*get_res(cmd.data.res.b));
        break;
    case b_div8:
        set_res_chr(cmd.data.res.c, get_res_chr(cmd.data.res.a)/get_res_chr(cmd.data.res.b));
        break;
    case b_div64:
        set_res(cmd.data.res.c, get_res(cmd.data.res.a)/get_res(cmd.data.res.b));
        break;



    case io_im:
        set_mem(cmd.data.mem, getchar());
        break;
    case io_ir:
        set_res_chr(cmd.data.res.a, getchar());
        break;
    case io_oi:
        putchar(cmd.data.data8);
        break;
    case io_or:
        putchar(get_res_chr(cmd.data.res.a));
        break;
    case io_om:
        putchar(get_mem(cmd.data.mem));
        break;

    default:
        break;
    }
    set_res(RES_LN, get_res(RES_LN) + 1);
    return(false);
}

vm_template
void VM<res_size>::run(UINT64 entry0){
    set_res(RES_LN, entry0);
    bool tmp = 0;
    while (!tmp){
        command * dd = (command *)(mem+get_res(RES_LN));
        tmp = run_command(*dd);
    }
}

#endif
