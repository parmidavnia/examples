
input: debug_enable_list=List([node_id],[i_0,i_1,...]), expected_list = List([node_id],[i_0,i_1,...],[guard_value]) 
// list of the nodes givne as input to the algorithm, for first tun op_list={store_ID[], br_ID[], ret_ID, carry_dep[]}
output: memorybuffer= List(datapacket) //nodes that resulted in the wrong result
datapacket = List([node_id],[i_0,i_1,...],[helper values of the node])
//the first 8 left bits of the data packet are given to the sw algorithm as op_list input. the rest are for additional information for the user in saved faulty nodes  

for (i in debug_enable_list.node_id){
    for (j in id_list.iterations[i]){
        if (node[i][j].value != node[i][j].guard_value)
            node[i][j].output = node[i][j].guard_value
           node.[i][j].datapacket.flag = 1
        }
     memorybuffer.append(node[i][j].datapacket)

}
