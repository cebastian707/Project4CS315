/*By:: Cebastian Santiago 
* GrpahNode Class CS315 Project 4
*/
#pragma once
#ifndef _GraphNode_hpp
#define _GraphNode_hpp
#include<iostream>
#include<string>
#include<vector>
class GraphNode {
public:
    /// @brief constructor for the class GraphNode
    /// @param name 
    GraphNode(std::string name);
    /// @brief 
    /// @returns name of a file
    std::string getName();
    /// @brief sets name equal _name
    /// @param name 
    void setName(std::string name);
    /// @brief sets ts equal timestamp
    /// @param ts 
    void setTimestamp(int ts);
    /// @brief 
    /// @returns _timestamp of a file 
    int getTimestamp();
    /// @brief 
    /// @returns the vector of the dependent nodes
    std::vector<GraphNode*>* dependentNodes();
    /// @brief sets cmnd equal to _command
    /// @param cmnd 
    void setCommand(std::string cmnd);
    /// @brief 
    /// @returns the _command  
    std::string getCommand();
    /// @brief excutes the command using systemInterface
    void runCommand();  // execute the command associated with this node. Only for target nodes.
    /// @brief adds child dependcy to the vector
    /// @param child 
    void addDependentNode(GraphNode* child);
    /// @brief 
    /// @returns _OnPath
    bool onPath();
    /// @brief sets v equal to OnPath
    /// @param v 
    void onPath(bool v);
    /// @brief 
    /// @returns _wasMade 
    bool wasMade();
    /// @brief sets v equal to _wasMade
    /// @param v 
    void wasMade(bool v);
    /// @brief 
    /// @returns _isATarget 
    bool isATarget();
    /// @brief sets v equal to _isATarget
    /// @param v 
    void isATarget(bool v);
    /// @brief 
    /// @returns the number of nodes in the vector of  _listOfDependentNodes
    int numDependentNodes();
    /// @brief prints something _name ???
    void print();
private:
    /// @brief private variables of the class GraphNode
    std::string _name, _command;
    int _timestamp;
    std::vector<GraphNode*>* _listOfDependentNodes;
    bool _onPath, _isATarget, _wasMade;
};
#endif