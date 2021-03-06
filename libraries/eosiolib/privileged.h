#pragma once

#ifdef __cplusplus
extern "C" {
#endif

   /**
    * @defgroup privileged_c Privileged C API
    * @ingroup c_api
    * @brief Defines %C Privileged API
    */

    /**
    * Get the resource limits of an account
    *
    * @param account - name of the account whose resource limit to get
    * @param ram_bytes - pointer to `int64_t` to hold retrieved ram limit in absolute bytes
    * @param net_weight - pointer to `int64_t` to hold net limit
    * @param cpu_weight - pointer to `int64_t` to hold cpu limit
    */
   void get_resource_limits( capi_name account, int64_t* ram_bytes, int64_t* net_weight, int64_t* cpu_weight );

   /**
    * Set the resource limits of an account
    *
    * @param account - name of the account whose resource limit to be set
    * @param ram_bytes - ram limit in absolute bytes
    * @param net_weight - fractionally proportionate net limit of available resources based on (weight / total_weight_of_all_accounts)
    * @param cpu_weight - fractionally proportionate cpu limit of available resources based on (weight / total_weight_of_all_accounts)
    */
   void set_resource_limits( capi_name account, int64_t ram_bytes, int64_t net_weight, int64_t cpu_weight );

   /**
    * Proposes a schedule change
    *
    * @note Once the block that contains the proposal becomes irreversible, the schedule is promoted to "pending" automatically. Once the block that promotes the schedule is irreversible, the schedule will become "active"
    * @param producer_data - packed data of produce_keys in the appropriate producer schedule order
    * @param producer_data_size - size of the data buffer
    *
    * @return -1 if proposing a new producer schedule was unsuccessful, otherwise returns the version of the new proposed schedule
    */
   int64_t set_proposed_producers( char *producer_data, uint32_t producer_data_size );

   /**
    * Set new active producers. Producers will only be activated once the block which starts the next round is irrreversible
    *
    * @param producer_data - pointer to producer schedule packed as bytes
    * @param producer_data_size - size of the packed producer schedule
    * @pre `producer_data` is a valid pointer to a range of memory at least `producer_data_size` bytes long that contains serialized produced schedule data
    */
   void set_active_producers( char *producer_data, uint32_t producer_data_size );
   /**
    * Check if an account is privileged
    *
    * @param account - name of the account to be checked
    * @return true if the account is privileged
    * @return false if the account is not privileged
    */
   bool is_privileged( capi_name account );

   /**
    * Set the privileged status of an account
    *
    * @param account - name of the account whose privileged account to be set
    * @param is_priv - privileged status
    */
   void set_privileged( capi_name account, bool is_priv );

   /**
    * Set the blockchain parameters
    *
    * @param data - pointer to blockchain parameters packed as bytes
    * @param datalen - size of the packed blockchain parameters
    * @pre `data` is a valid pointer to a range of memory at least `datalen` bytes long that contains packed blockchain params data
    */
   void set_blockchain_parameters_packed( char* data, uint32_t datalen );

   /**
    * Retrieve the blolckchain parameters
    *
    * @param data - output buffer of the blockchain parameters, only retrieved if sufficent size to hold packed data.
    * @param datalen - size of the data buffer, 0 to report required size.
    * @return size of the blockchain parameters
    * @pre `data` is a valid pointer to a range of memory at least `datalen` bytes long
    * @post `data` is filled with packed blockchain parameters
    */
   uint32_t get_blockchain_parameters_packed( char* data, uint32_t datalen );
   
   /* bos */
   /**
    * @brief Set the name list packed object
    * Set the name list packed object
    * @param list     blacklist type enum type value include 1-actor_blacklist_type  2-contract_blacklist_type 3-resource_greylist_type
    * @param action   list action type enum type value include 1- insert_type 2-remove_type
    * @param data     vector<string> fc pack  data  char* type
    * @param datalen  the length of the data.
    */
   void set_name_list_packed(int64_t list, int64_t action, char* data, uint32_t datalen);

   void set_upgrade_parameters_packed( char* data, uint32_t datalen );

   /**
    * @brief Set the guaranteed minimum resources object
    * Set the guaranteed minimum resources object
    * @param ram gift ram bytes
    * @param cpu gift cpu microsecond
    * @param net gift net bytes
    */
   void set_guaranteed_minimum_resources(int64_t ram, int64_t cpu, int64_t net);
   /* bos end */

#ifdef __cplusplus
}
#endif
