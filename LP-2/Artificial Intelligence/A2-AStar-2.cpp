#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Node
{
public:
    Node(Node *parent, pair<int, int> position)
        : parent(parent), position(position), g(0), h(0), f(0) {}

    bool operator==(const Node &other) const
    {
        return position == other.position;
    }

    Node *parent;
    pair<int, int> position;
    int g, h, f;
};

vector<pair<int, int>> astar(vector<vector<int>> &maze, pair<int, int> start, pair<int, int> end)
{
    Node *startNode = new Node(nullptr, start);
    startNode->g = startNode->h = startNode->f = 0;

    Node *endNode = new Node(nullptr, end);
    endNode->g = endNode->h = endNode->f = 0;

    vector<Node *> openList;
    vector<Node *> closedList;

    openList.push_back(startNode);

    while (!openList.empty())
    {
        Node *currentNode = openList[0];
        int currentIndex = 0;

        for (int i = 0; i < openList.size(); ++i)
        {
            if (openList[i]->f < currentNode->f)
            {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        openList.erase(openList.begin() + currentIndex);
        closedList.push_back(currentNode);

        if (*currentNode == *endNode)
        {
            vector<pair<int, int>> path;
            Node *current = currentNode;

            while (current != nullptr)
            {
                path.push_back(current->position);
                current = current->parent;
            }

            reverse(path.begin(), path.end());
            return path;
        }

        vector<Node *> children;
        for (auto &newPosition : {make_pair(0, -1), make_pair(0, 1), make_pair(-1, 0), make_pair(1, 0),
                                  make_pair(-1, -1), make_pair(-1, 1), make_pair(1, -1), make_pair(1, 1)})
        {
            pair<int, int> nodePosition = {currentNode->position.first + newPosition.first, currentNode->position.second + newPosition.second};

            if (nodePosition.first > (maze.size() - 1) || nodePosition.first < 0 ||
                nodePosition.second > (maze[maze.size() - 1].size() - 1) || nodePosition.second < 0)
            {
                continue;
            }

            if (maze[nodePosition.first][nodePosition.second] != 0)
            {
                continue;
            }

            Node *newNode = new Node(currentNode, nodePosition);
            children.push_back(newNode);
        }

        for (auto &child : children)
        {
            for (auto &closedChild : closedList)
            {
                if (*child == *closedChild)
                {
                    continue;
                }
            }

            child->g = currentNode->g + 1;
            child->h = std::pow((child->position.first - endNode->position.first), 2) + pow((child->position.second - endNode->position.second), 2);
            child->f = child->g + child->h;

            for (auto &openNode : openList)
            {
                if (*child == *openNode && child->g > openNode->g)
                {
                    continue;
                }
            }

            openList.push_back(child);
        }
    }

    return {}; // No path found
}

int main()
{
    vector<vector<int>> maze = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    pair<int, int> start = {0, 0};
    pair<int, int> end = {9, 9};

    vector<pair<int, int>> path = astar(maze, start, end);

    for (const auto &point : path)
    {
        cout << "(" << point.first << ", " << point.second << ") ";
    }

    return 0;
}
